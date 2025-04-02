import json
from datamodel import OrderDepth, TradingState, Order
from typing import Dict, List

# === Logger setup - can ignore, it's just for compatibility with IMC visualizer ===
class Logger:
    def __init__(self) -> None:
        self.logs = ""
        self.max_log_length = 3750

    def print(self, *objects: Any, sep: str = " ", end: str = "\n") -> None:
        self.logs += sep.join(map(str, objects)) + end

    def flush(self, state: TradingState, orders: dict[Symbol, List[Order]], conversions: int, trader_data: str) -> None:
        base_length = len(self.to_json([
            self.compress_state(state, ""),
            self.compress_orders(orders),
            conversions, "", ""
        ]))

        max_item_length = (self.max_log_length - base_length) // 3

        print(self.to_json([
            self.compress_state(state, self.truncate(state.traderData, max_item_length)),
            self.compress_orders(orders),
            conversions,
            self.truncate(trader_data, max_item_length),
            self.truncate(self.logs, max_item_length)
        ]))

        self.logs = ""

    def compress_state(self, state: TradingState, trader_data: str) -> list[Any]:
        return [
            state.timestamp,
            trader_data,
            [[l.symbol, l.product, l.denomination] for l in state.listings.values()],
            {s: [od.buy_orders, od.sell_orders] for s, od in state.order_depths.items()},
            [[t.symbol, t.price, t.quantity, t.buyer, t.seller, t.timestamp] for trades in state.own_trades.values() for t in trades],
            [[t.symbol, t.price, t.quantity, t.buyer, t.seller, t.timestamp] for trades in state.market_trades.values() for t in trades],
            state.position,
            [state.observations.plainValueObservations, {
                p: [
                    o.bidPrice, o.askPrice, o.transportFees,
                    o.exportTariff, o.importTariff,
                    o.sugarPrice, o.sunlightIndex
                ] for p, o in state.observations.conversionObservations.items()
            }]
        ]

    def compress_orders(self, orders: dict[Symbol, List[Order]]) -> list[list[Any]]:
        return [[o.symbol, o.price, o.quantity] for order_list in orders.values() for o in order_list]

    def to_json(self, value: Any) -> str:
        return json.dumps(value, cls=ProsperityEncoder, separators=(",", ":"))

    def truncate(self, value: str, max_length: int) -> str:
        return value if len(value) <= max_length else value[:max_length - 3] + "..."

logger = Logger()

# === Trader class ===
class Trader:
    def __init__(self):
        self.pnl = {}  # This will be stored in traderData each tick

    def load_trader_data(self, trader_data: str):
        if trader_data:
            self.pnl = json.loads(trader_data)
        else:
            self.pnl = {}

    def update_profit(self, trades, product, position):
        # Update self.pnl based on recent trades
        for trade in trades.get(product, []):
            if trade.buyer == "SUBMISSION":
                # We bought (spend money)
                self.pnl[product] = self.pnl.get(product, 0) - trade.price * trade.quantity
            elif trade.seller == "SUBMISSION":
                # We sold (earned money)
                self.pnl[product] = self.pnl.get(product, 0) + trade.price * trade.quantity

    def calculate_vwap(self, price_volume_dict):
        total_volume = 0
        total_value = 0
        for price, volume in price_volume_dict.items():
            volume = abs(volume)
            total_value += price * volume
            total_volume += volume
        if total_volume == 0:
            return None
        return total_value / total_volume

class Trader:

    def run(self, state: TradingState) -> Dict[str, List[Order]]:
        
        # Initialize the method output dict as an empty dict
        result = {}

        # Iterate over all the keys (the available products) contained in the order dephts
        for product in state.order_depths.keys():

                # Retrieve the Order Depth containing all the market BUY and SELL orders
                order_depth: OrderDepth = state.order_depths[product]

                # Initialize the list of Orders to be sent as an empty list
                orders: list[Order] = []

                # Note that this value of 1 is just a dummy value, you should likely change it!
                acceptable_price = 10

                # If statement checks if there are any SELL orders in the market
                if len(order_depth.sell_orders) > 0:

                    # Sort all the available sell orders by their price,
                    # and select only the sell order with the lowest price
                    best_ask = min(order_depth.sell_orders.keys())
                    best_ask_volume = order_depth.sell_orders[best_ask]

                    # Check if the lowest ask (sell order) is lower than the above defined fair value
                    if best_ask < acceptable_price:

                        # In case the lowest ask is lower than our fair value,
                        # This presents an opportunity for us to buy cheaply
                        # The code below therefore sends a BUY order at the price level of the ask,
                        # with the same quantity
                        # We expect this order to trade with the sell order
                        print("BUY", str(-best_ask_volume) + "x", best_ask)
                        orders.append(Order(product, best_ask, -best_ask_volume))

                # The below code block is similar to the one above,
                # the difference is that it find the highest bid (buy order)
                # If the price of the order is higher than the fair value
                # This is an opportunity to sell at a premium
                if len(order_depth.buy_orders) != 0:
                    best_bid = max(order_depth.buy_orders.keys())
                    best_bid_volume = order_depth.buy_orders[best_bid]
                    if best_bid > acceptable_price:
                        print("SELL", str(best_bid_volume) + "x", best_bid)
                        orders.append(Order(product, best_bid, -best_bid_volume))

                # Add all the above the orders to the result dict
                result[product] = orders
                
        traderData = "SAMPLE" # String value holding Trader state data required. It will be delivered as TradingState.traderData on next execution.
        
        conversions = 1 

                # Return the dict of orders
                # These possibly contain buy or sell orders
                # Depending on the logic above
        
        return result, conversions, traderData



import json
from typing import List, Any
from datamodel import OrderDepth, Order, TradingState, Symbol, ProsperityEncoder

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

    def run(self, state: TradingState):
        POSITION_LIMIT = 50  # Limit of 50 per item
        logger.print(f"--- Tick {state.timestamp} ---")
        logger.print("My position:", state.position)

        result = {}

        # Focus on specific products: KELP and RAINFOREST_RESIN
        for product in ["KELP", "RAINFOREST_RESIN"]:
            if product not in state.order_depths:
                continue

            orders = []
            order_depth = state.order_depths[product]

            buy_orders = order_depth.buy_orders
            sell_orders = order_depth.sell_orders

            if not buy_orders or not sell_orders:
                continue

            # Calculate the best bid, best ask, and VWAP
            best_bid = max(buy_orders.keys())
            best_ask = min(sell_orders.keys())

            vwap_buy = self.calculate_vwap(buy_orders)
            vwap_sell = self.calculate_vwap(sell_orders)

            # Determine the fair price
            if vwap_buy and vwap_sell:
                fair_price = (vwap_buy + vwap_sell) / 2
            else:
                fair_price = (best_bid + best_ask) / 2

            logger.print(f"[{product}] VWAP Buy: {vwap_buy}, VWAP Sell: {vwap_sell}, Fair: {fair_price}")

            # Get the current position for the product
            current_position = state.position.get(product, 0)

            # Place buy orders if the ask price is below the fair price
            for ask_price, ask_volume in sorted(sell_orders.items()):
                if ask_price < fair_price and current_position < POSITION_LIMIT:
                    qty = min(-ask_volume, POSITION_LIMIT - current_position)
                    if qty > 0:  # Ensure we don't place zero-quantity orders
                        orders.append(Order(product, ask_price, qty))
                        current_position += qty

            # Place sell orders if the bid price is above the fair price
            for bid_price, bid_volume in sorted(buy_orders.items(), reverse=True):
                if bid_price > fair_price and current_position > -POSITION_LIMIT:
                    qty = min(bid_volume, current_position + POSITION_LIMIT)
                    if qty > 0:  # Ensure we don't place zero-quantity orders
                        orders.append(Order(product, bid_price, -qty))
                        current_position -= qty

            # Add the orders for this product to the result
            result[product] = orders

        # Update profit and loss (PnL)
        for product in state.market_trades:
            self.update_profit(state.market_trades, product, state.position.get(product, 0))

        # Flush logs and return the result
        logger.flush(state, result, 0, json.dumps(self.pnl))
        return result, 0, json.dumps(self.pnl)
    


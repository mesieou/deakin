#include "utilities.h"
#include "splashkit.h"
#include <string>

using std::string;
using std::to_string;

const int NUM_COIN_TYPES = 6;
const int TWO_DOLLARS = 200;
const int ONE_DOLLAR = 100;
const int FIFTY_CENTS = 50;
const int TWENTY_CENTS = 20;
const int TEN_CENTS = 10;
const int FIVE_CENTS = 5;

void give_change(int change)
{
    int coin_value, coin_quantity;
    int curr_change = change * 100;
    string coin_text;
    
    for(int i = 0; i < NUM_COIN_TYPES; i++)
    {
        switch (i)
        {
        case 0:
            coin_value = TWO_DOLLARS;
            coin_text = "$2, ";
            break;
        case 1:
            coin_value = ONE_DOLLAR;
            coin_text = "$1, ";
            break;
        case 2:
            coin_value = FIFTY_CENTS;
            coin_text = "50c, ";
            break;
        case 3:
            coin_value = TWENTY_CENTS;
            coin_text = "20c, ";
            break;
        case 4:
            coin_value = TEN_CENTS;
            coin_text = "10c, ";
            break;
        case 5:
            coin_value = FIVE_CENTS;
            coin_text = "5c, ";
            break;
        }
        coin_quantity = curr_change / coin_value;
        curr_change -= coin_value * coin_quantity;
        write_line(to_string(coin_quantity) + " x " + coin_text);
    }
}


int main()
{
    int item_cost, amount_paid;
    string again = "";

    do
    {
        item_cost = read_integer("Please enter the cost: ");
        amount_paid = read_integer("Please enter the amount paid: ");
        
        if(amount_paid >= item_cost)
        {
            give_change(amount_paid - item_cost);
        } else {
            write_line("How came you paid less than what it costs?");
        }

        write_line("Would you like to start over: [y or n]");
        again = read_line();

    } while (again != "n" && again != "N");
    
}
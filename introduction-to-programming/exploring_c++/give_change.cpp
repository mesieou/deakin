#include "splashkit.h"
#include <sstream>  // For stringstream

using std::to_string;
using namespace std;

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

string read_string(string prompt)
{
    write_line(prompt);
    return read_line();
}

int read_integer(string prompt, 
                 int from = numeric_limits<int>::min(), 
                 int to = numeric_limits<int>::max())
{
    string user_output = read_string(prompt);
    
    while(!is_integer(user_output))
    {
        write_line("Please enter a whole number./n");
        user_output = read_string(prompt);
    }

    int user_output_int = convert_to_integer(user_output);
    while (!(user_output_int > from and user_output_int < to))
    {
        stringstream ss;
        ss << "Please enter a number from " << from << " to " << to;

        write_line( ss.str());
        user_output_int = convert_to_integer(read_string(prompt));
    } 

    return user_output_int;
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
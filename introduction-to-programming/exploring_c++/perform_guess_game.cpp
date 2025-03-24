#include "splashkit.h"
#include <sstream>  // For stringstream

using std::to_string;
using namespace std;

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

bool perform_guess(int attempt_number, int target)
{
    int guess = read_integer("Guess " + to_string(attempt_number) + ": " );
    if(guess < target)
    {
        write_line("The number is larger than " + to_string(guess));
    } else if (guess > target)
    {
        write_line("The number is less than " + to_string(guess));
    } else 
    {
        write_line("Well done. The number was  " + to_string(guess));
    }
    return guess == target;
}

int main()
{   
    perform_guess(1, 37);
    perform_guess(2, 37);
    perform_guess(3, 37);
    return 0;
}
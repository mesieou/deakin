#include "splashkit.h"
#include <sstream>  // For stringstream

using std::to_string;
using namespace std;

const int MAX_NUMBER = 100;
const int MAX_GUESSES = 7;

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

void play_game()
{
    int random_int = rnd(1, MAX_NUMBER);
    int guess_number = 0;
    bool guess_result;
    
    write_line("Try to guess a number between 1 and " + to_string(MAX_NUMBER));   
    

    do
    {
        guess_number++;
        guess_result = perform_guess(guess_number, random_int);
    } while (guess_number < MAX_GUESSES && !guess_result);

    if(!guess_result)
    {
        write_line("You ran out of guesses... the numbers was " + to_string(random_int));
    }
}

int main()
{   
    play_game();
    return 0;
}
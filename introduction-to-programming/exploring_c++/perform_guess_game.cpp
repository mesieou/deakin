#include "splashkit.h"
#include "utilities.h"

const int MAX_NUMBER = 100;
const int MAX_GUESSES = 7;


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

void print_repeated(string text, int times, bool with_newline)
{
  for (int i = 0; i < times; i++)
  {
    write(text);
  }

  if (with_newline)
  {
    write_line("\n");
  }
}

void print_line(int length)
{
  print_repeated("-", length, true);
}

int main()
{   
    string play_again;
    do
    {
        play_game();
        print_line(25);
        write_line("Play again? [Y or N]: ");
        play_again = read_line();
    } while (play_again != "n" && play_again != "N");
    
    return 0;
}
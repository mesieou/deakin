#include "splashkit.h"

// Prints a line based on the user's input
void print_line(int length)
{
    for (int i = 0; i < length; i++)
    {
        write('-');
    }  
}

int main()
{
  string input;
  int test_length;

  write("Enter a length for a test line: ");
  input = read_line();
  test_length = stoi(input);

  print_line(test_length);
}
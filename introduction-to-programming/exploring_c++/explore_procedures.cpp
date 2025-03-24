#include "splashkit.h"


// prints anything a number of times with a space at the end if needed
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
  string input;
  int test_length;

  print_line(20);
  write_line("| Line print test  |");
  print_line(20);

  print_repeated("--+--+", 5, true);
  print_repeated("Hello World\n", 5, false);
  print_repeated("--+--+", 5, true);

  write("Enter a length for a test line: ");
  input = read_line();
  test_length = stoi(input);

  print_line(test_length);
}
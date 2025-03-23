#include "splashkit.h"

string read_string(string prompt)
{
    write_line(prompt);
    return read_line();
}

int main()
{
  string name;

  // Read in a string and store it in name
  name = read_string("enter your name: ");

  // Output the name
  write_line("Hello " + name);

  return 0;
}
#include "splashkit.h"
using std::to_string;

string read_string(string prompt)
{
    write_line(prompt);
    return read_line();
}

int read_integer(string prompt)
{
    string user_output = read_string(prompt);
    while(!is_integer(user_output))
    {
        write_line("Please enter a whole number.");
        user_output = read_string(prompt);
    }
    return convert_to_integer(user_output);
}

int main()
{
  string name;
  int age;

  // Read in a string and store it in name
  name = read_string("enter your name: ");

  // Output the name
  write_line("Hello " + name);

  // Read in an integer
  age = read_integer("what is your age: ");

  write_line("You entered " + to_string(age));

  return 0;
}
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


int main()
{
  string name;
  int age;

  // Read in a string and store it in name
  name = read_string("Enter your name: ");

  // Output the name
  write_line("Hello " + name);

  // Read in an integer
  age = read_integer("what is your age: ", 1, 10);

  write_line("You entered " + to_string(age));

  return 0;
}
#include "utilities.h"
#include "splashkit.h"

#include <string>
#include <sstream>  // For stringstream

using std::to_string;
using namespace std;
using std::string;

string read_string(string prompt)
{
    write_line(prompt);
    return read_line();
}

int read_integer(string prompt, int from, int to)  // No default arguments here
{
    string user_output = read_string(prompt);
    
    while(!is_integer(user_output))
    {
        write_line("Please enter a whole number");
        user_output = read_string(prompt);
    }

    int user_output_int = convert_to_integer(user_output);
    while (!(user_output_int >= from and user_output_int <= to))
    {
        stringstream ss;
        ss << "Please enter a number from " << from << " to " << to;

        write_line( ss.str());
        user_output_int = convert_to_integer(read_string(prompt));
    }
    return user_output_int;
}

double read_double(string prompt, double from, double to)
{
    string user_output = read_string(prompt);
    
    while(!is_double(user_output))
    {
        write_line("Please enter a valid decimal number");
        user_output = read_string(prompt);
    }

    double user_output_double = convert_to_double(user_output);
    while (!(user_output_double >= from && user_output_double <= to))
    {
        stringstream ss;
        ss << "Please enter a number from " << from << " to " << to;
        write_line(ss.str());
        user_output_double = convert_to_double(read_string(prompt));
    }
    return user_output_double;
}

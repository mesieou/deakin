#include "splashkit.h"
#include <sstream>
#include <cstdlib> 

using std::to_string;
using namespace std;

//permission levels structure
enum permissions_level_data
{
    NO_ACCESS,
    USER,
    ADMIN,
    SUPER_USER

};

//user structure
struct user_data
{
    string username;
    string password;
    permissions_level_data permissions_level;

};

// read and return a user string input
string read_string(string prompt)
{
    write_line(prompt);
    return read_line();
}

// read and return a user number input and checks it is a number
int read_integer(string prompt, 
    int from = numeric_limits<int>::min(), 
    int to = numeric_limits<int>::max())
{
    string user_output = read_string(prompt);
    
    while(!is_integer(user_output))
    {
        write_line("Please enter a whole number");
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
  user_data user = {
    "my_user_name",
    USER
  };

  print_user(user);

  return 0;
}
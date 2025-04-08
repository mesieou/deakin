#include "splashkit.h"
#include <sstream>
#include <cstdlib> 

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
    while (!(user_output_int >= from and user_output_int <= to))
    {
        stringstream ss;
        ss << "Please enter a number from " << from << " to " << to;

        write_line( ss.str());
        user_output_int = convert_to_integer(read_string(prompt));
    }
    return user_output_int;
}

string permission_to_string( permissions_level_data permission)
{
    switch (permission)
    {
    case NO_ACCESS:
        return "No access";
        break;
    case USER:
        return "USER";
        break;
    case ADMIN:
        return "Admin";
        break;
    case SUPER_USER:
        return "Super User";
        break;
    
    default:
        return "Unknown role";
    }
}

permissions_level_data read_role()
{
    int role_input = read_integer("Enter rol level(0 for none, 1 for USER, 2 for Admin)", 0, 2);

    switch (role_input)
    {
    case 0:
        return NO_ACCESS;
        break;
    case 1:
        return USER;
        break;
    case 2:
        return ADMIN;
        break;
    default:
        return NO_ACCESS;
    }
}

void print_user( user_data user)
{
    write_line("");
    write_line("User name: " + user.username);
    write_line("Role: " + permission_to_string(user.permissions_level));
}

void update_user(user_data &user)
{
    user.username = "Juan";
}

int main()
{
    
    permissions_level_data role = read_role();
    user_data user = {
        "my_user_name",
        "sfafas", // username
        role            // permission level
    };

  print_user(user);
  update_user(user);
  print_user(user);


  return 0;
}
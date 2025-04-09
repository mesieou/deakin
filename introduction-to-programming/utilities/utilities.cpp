#include "utilities.h"
#include "splashkit.h"

#include <string>
#include <sstream>  // For stringstream

using std::to_string;
using namespace std;
using std::string;

const int MAX_LIST = 100;

// Define the struct with an array and its size
struct list_data
{
    double values[MAX_LIST];
    int size;
};

void print_list(list_data data)
{
    for (int i = 0; i < data.size; i++)
    {
        printf("%d: %lf\n", i + 1, data.values[i]);
    }
}

// adds more numbers to the number data array
void push(list_data &data) {
    int num = read_integer("Enter the number to add");
    // Ensures we do not pass the max size of the array
    if (data.size >= MAX_LIST)
    {
        printf("Error. The max numbers is %d", MAX_LIST);
    }

    // Ensures the array size is equal or more than 0
    if (data.size < 0)
    {
        data.size = 0;
    }
    
    data.values[data.size] = num;
    data.size++;
}

// asks the user to select which element of the list to remove
void remove(list_data &data) {
    print_list(data);

    int index = read_integer("Enter the number of the number to delete");
    if (index < 0 || index > data.size)
    {
        printf("Error. The number does not exits");
    }
    data.values[index] = data.values[data.size - 1];
    data.size--;
}

//calculate the maximum number in the array
double max(list_data data) {
    // Ensure there is data
    if (data.size == 0)
    {
        return 0;
    }
    // Assume the first value is the largest
    double max = data.values[0];

    // Check the rest of the values for a largar number
    for (int i = 1; i< data.size; i++)
    {
        if (max > data.values[i])
        {
            max = data.values[0];
        }
    }
    return max;
}

// calculate the sum of all the elements in the array
double sum(list_data &nums) {
    double total = 0;
    for (int i = 0; i < nums.size; i++)
    {
        total += nums.values[i];
    }
    return total;
}

// calculate the mean of all the elements in the array
double mean(list_data &data) {
    // Ensures there is data or it returns 0
    if (data.size == 0)
    {
        return 0;
    }

    return sum(data) / data.size;
}

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


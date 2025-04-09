#include "utilities.h"
#include "splashkit.h"

#include <cstdio>
#include <string>
#include <sstream>  // For stringstream

using std::to_string;
using namespace std;
using std::string;

void print_list_int(ints_list data)
{
    for (int i = 0; i < data.size; i++)
    {
        printf("%d: %d\n", i + 1, (int)data.values[i]);
    }
}

void print_list_double(doubles_list data)
{
    for (int i = 0; i < data.size; i++)
    {
        printf("%d: %.2f\n", i + 1, data.values[i]);
    }
}

void print_list_string(strings_list data)
{
    for (int i = 0; i < data.size; i++)
    {
        printf("%d: %s\n", i + 1, data.values[i].c_str());
    }
}

// Adds more integers to the integer data array
void push_int(ints_list &data, int num) {
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

void push_double(doubles_list &data, double num) {
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

// Adds more strings to the string data array
void push_string(strings_list &data, string str) {
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

    data.values[data.size] = str;
    data.size++;
}

// Asks the user to select which element of the list to remove (for integers)
void remove_int(ints_list &data) {
    int index = read_integer("Enter the number of the number to delete", 1, data.size);
    if (index < 0 || index > data.size)
    {
        printf("Error. The number does not exist");
    }
    data.values[index - 1] = data.values[data.size - 1];  // Adjust for zero-indexing
    data.size--;
}

void remove_double(doubles_list &data) {
    int index = read_integer("Enter the number of the number to delete", 1, data.size);
    if (index < 0 || index > data.size)
    {
        printf("Error. The number does not exist");
    }
    data.values[index - 1] = data.values[data.size - 1];  // Adjust for zero-indexing
    data.size--;
}

// Asks the user to select which element of the list to remove (for strings)
void remove_string(strings_list &data) {
    int index = read_integer("Enter the number of the string to delete", 1, data.size);
    if (index < 0 || index > data.size)
    {
        printf("Error. The string does not exist");
    }
    data.values[index - 1] = data.values[data.size - 1];  // Adjust for zero-indexing
    data.size--;
}

// Calculate the maximum number in the array for integers
double max_int(ints_list &data) {
    // Ensure there is data
    if (data.size == 0)
    {
        return 0;
    }
    // Assume the first value is the largest
    double max = data.values[0];

    // Check the rest of the values for a larger number
    for (int i = 1; i < data.size; i++)
    {
        if (max < data.values[i])
        {
            max = data.values[i];
        }
    }
    return max;
}

// Calculate the maximum number in the array for doubles
double max_double(doubles_list &data) {
    // Ensure there is data
    if (data.size == 0)
    {
        return 0;
    }
    // Assume the first value is the largest
    double max = data.values[0];

    // Check the rest of the values for a larger number
    for (int i = 1; i < data.size; i++)
    {
        if (max < data.values[i])
        {
            max = data.values[i];
        }
    }
    return max;
}

// Calculate the sum of all the elements in the integer array
double sum_int(ints_list &nums) {
    double total = 0;
    for (int i = 0; i < nums.size; i++)
    {
        total += nums.values[i];
    }
    return total;
}

// Calculate the sum of all the elements in the double array
double sum_double(doubles_list &nums) {
    double total = 0;
    for (int i = 0; i < nums.size; i++)
    {
        total += nums.values[i];
    }
    return total;
}

// Calculate the mean of all the elements in the integer array
double mean_int(ints_list &data) {
    // Ensures there is data or it returns 0
    if (data.size == 0)
    {
        return 0;
    }

    return sum_int(data) / data.size;
}

// Calculate the mean of all the elements in the double array
double mean_double(doubles_list &data) {
    // Ensures there is data or it returns 0
    if (data.size == 0)
    {
        return 0;
    }

    return sum_double(data) / data.size;
}

string read_string(string prompt)
{
    write_line(prompt);
    return read_line();
}

int read_integer(string prompt, int from, int to)
{
    string user_output = read_string(prompt);
    
    while(!is_integer(user_output))
    {
        write_line("Please enter a whole number");
        user_output = read_string(prompt);
    }

    int user_output_int = convert_to_integer(user_output);
    while (!(user_output_int >= from && user_output_int <= to))
    {
        stringstream ss;
        ss << "Please enter a number from " << from << " to " << to;
        write_line(ss.str());
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

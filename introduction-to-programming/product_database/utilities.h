#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <limits>
#include <sstream>

using std::string;
using std::numeric_limits;
using std::to_string;

const int MAX_LIST = 100;

// Structs for holding different data types
struct doubles_list
{
    double values[MAX_LIST];
    int size;
};

struct strings_list
{
    string values[MAX_LIST];
    int size;
};

struct ints_list
{
    int values[MAX_LIST];
    int size;
};

// User input functions
string read_string(string prompt);

int read_integer(string prompt, 
                 int from = numeric_limits<int>::min(), 
                 int to = numeric_limits<int>::max());

double read_double(string prompt, 
                   double from = numeric_limits<double>::min(), 
                   double to = numeric_limits<double>::max());

// Doubles list functions
void push_double(doubles_list &data, double num);
void remove_double(doubles_list &data);
void print_list_double(doubles_list data);
double sum_double(doubles_list &data);
double mean_double(doubles_list &data);
double max_double(doubles_list &data);

// Strings list functions
void push_string(strings_list &data, string str);
void remove_string(strings_list &data);
void print_list_string(strings_list data);

// Ints list functions
void push_int(ints_list &data, int numb);
void remove_int(ints_list &data);
void print_list_int(ints_list data);
double sum_int(ints_list &data);
double mean_int(ints_list &data);
double max_int(ints_list &data);

#endif

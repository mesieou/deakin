#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <sstream>  // For stringstream
#include <limits>

using std::to_string;
using namespace std;
using std::string;

const int MAX_LIST = 100;

// Struct to hold list data
struct list_data
{
    double values[MAX_LIST];
    int size;
};

// Function declarations
string read_string(string prompt);

int read_integer(string prompt, 
                 int from = numeric_limits<int>::min(), 
                 int to = numeric_limits<int>::max());

double read_double(string prompt, 
                   double from = numeric_limits<int>::min(), 
                   double to = numeric_limits<int>::max());

void print_list(list_data data);

void push(list_data &data);

void remove(list_data &data);

double max(list_data data);

double sum(list_data &data);

double mean(list_data &data);

#endif

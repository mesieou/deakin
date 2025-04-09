#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <sstream>  // For stringstream

using std::to_string;
using namespace std;
using std::string;

string read_string(string prompt);

int read_integer(string prompt, 
                 int from = numeric_limits<int>::min(), 
                 int to = numeric_limits<int>::max());

double read_double(string prompt, 
                 double from = numeric_limits<int>::min(), 
                 double to = numeric_limits<int>::max());

#endif
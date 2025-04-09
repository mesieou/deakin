#include "utilities.h"
#include "splashkit.h"

#include <cstdio>

// The maximum number of values we can store
const int MAX_NUMBERS = 20;

//todo: add struct here
typedef struct
{
    double values[MAX_NUMBERS];
    int size;
} number_data;

//todo: add populate_array here
void populate_array(number_data &data) {
    
    int size = read_integer("Enter the number of values: ");

    if (size > MAX_NUMBERS)
    {
        write_line("Sorry the max number is 20");
        size = MAX_NUMBERS;
    } else if (size < 0)
    {
        data.size = 0;
    } 
    
    data.size = size;
    
    for (int i = 0; i < data.size; i++)
    {
        data.values[i] = read_double("Enter value " + to_string(i + 1) +":");
    }
    
}
//todo: add print here
void print(number_data data) {
    for (int i = 0; i < data.size; i++)
    {
        printf("%d: %lf\n", i, data.values[i]);
    }
    
}
//todo: add max here

//todo: add sum here
double sum_numbers(number_data &nums) {
    double total = 0;
    for (int i = 0; i < nums.size; i++)
    {
        total += nums.values[i];
    }
    return total;
}
//todo: add mean here

int main() {
    // Your code goes here
    number_data data = {{}, 0};

    populate_array(data);
    int sum = sum_numbers(data);
    write_line(sum);

    return 0;
}
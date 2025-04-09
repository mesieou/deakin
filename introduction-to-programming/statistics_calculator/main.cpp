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
double max(number_data data) {
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

//todo: add sum here
double sum(number_data &nums) {
    double total = 0;
    for (int i = 0; i < nums.size; i++)
    {
        total += nums.values[i];
    }
    return total;
}

//todo: add mean here
double mean(number_data &data) {
    // Ensures there is data or it returns 0
    if (data.size == 0)
    {
        return 0;
    }

    return sum(data) / data.size;
}

// Displays a menu to the user
void print_menu()
{
  printf("\nMenu\n");
  printf("1. Add a value\n");
  printf("2. Remove a value\n");
  printf("3. Print the values\n");
  printf("4. Calculate stats\n");
  printf("5. Quit\n");

}

// adds more numbers to the number data array
void push(number_data &data) {
    int num = read_integer("Enter the number to add");
    // Ensures we do not pass the max size of the array
    if (data.size >= MAX_NUMBERS)
    {
        printf("Error. The max numbers is %d", MAX_NUMBERS);
    }

    // Ensures the array size is equal or more than 0
    if (data.size < 0)
    {
        data.size = 0;
    }
    
    data.values[data.size] = num;
    data.size++;
}

// remove numbers from the number data array
void remove_at_index(number_data &data) {
    print(data);
    int index = read_integer("Enter the number of the number to delete");
    if (index < 0 || index > data.size)
    {
        printf("Error. The number does not exits");
    }
    data.values[index] = data.values[data.size - 1];
    data.size--;
}

void calculate_stats(number_data data) {
    printf("Mean: %lf\n", mean(data));
    printf("Highest: %lf\n", max(data));
    printf("Total: %lf\n", sum(data));
}

int main() {
    // Your code goes here
    number_data data = {{}, 0};

    populate_array(data);
    int option;
    do
    {
        print_menu();
        option = read_integer("Enter a number:");
        switch (option)
        {
        case 1:
            push(data);
            break;
        case 2:
            remove_at_index(data);
            break;
        case 3:
            print(data);
            break;
        case 4:
            calculate_stats(data);
            break;
        case 5:
            printf("bye bye");
            break;
        default:
            write_line("Unknown ooption, please enter a number from 1 to 5.");
            break;
        }
    } while (option != 5);
    

    return 0;
}
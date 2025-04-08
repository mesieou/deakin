#include "utilities.h"
#include "splashkit.h"


int total_length( string arr[], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += length_of(arr[i]);
    }
    return result;
}

int main()
{
    const int SIZE = 3;
    string my_first_array[3] = {"Juan", "David", "Bernal"};
     
    int index = 0;
    while (index < SIZE )
    {
        write_line(my_first_array[index]);
        index++;
        
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        write_line(my_first_array[i]);
    }

    int total_length_names = total_length(my_first_array, SIZE);
    write_line(total_length_names);
}
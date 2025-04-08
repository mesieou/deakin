#include "utilities.h"
#include "splashkit.h"

const int SIZE = 3;

int main()
{
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
    
    
}
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

string shortest_name(string arr[], int size) {
    string min = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (length_of(min) > length_of(arr[i]))
        {
            min = arr[i];
        }
    }
    return min;
 }

bool contains(string arr[], int size, string name) {
    for (int i = 0; i < size; i++)
    {
        if (to_lowercase(arr[i]) == to_lowercase(name))
        {
            return true;
        }
    }
    return false;
}


int main()
{
    const int SIZE = 3;
    string my_first_array[3] = {"Ju", "David", "Bernal"};
     

    int total_length_names = total_length(my_first_array, SIZE);
    string name = shortest_name(my_first_array, SIZE);
    write_line(name);
    
    bool david_in_arr = contains(my_first_array, SIZE, "davidd");
    write_line(david_in_arr);


}
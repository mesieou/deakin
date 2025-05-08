#include "utilities.h"
#include "splashkit.h"
#include <iostream>

#include <iostream>
#include <cstdlib>  // for realloc, malloc, free

template <typename T>
struct dynamic_array
{
    T *data;
    int size;
    int capacity;

    // Constructor
    dynamic_array(int initial_capacity = 10)
        : size(0), capacity(initial_capacity)
    {
        data = static_cast<T *>(malloc(sizeof(T) * capacity));
        if (!data) capacity = 0;
    }

    // Destructor
    ~dynamic_array()
    {
        free(data);
        data = nullptr;
    }

    // Resize member function
    bool resize(int new_capacity)
    {
        T *new_data = static_cast<T *>(realloc(data, sizeof(T) * new_capacity));
        if (!new_data) return false;

        data = new_data;
        capacity = new_capacity;
        if (size > capacity)
            size = capacity;

        return true;
    }

    // Add member function
    bool add(T value)
    {
        if (size == capacity)
        {
            int new_capacity = capacity == 0 ? 1 : capacity * 2;
            if (!resize(new_capacity)) return false;
        }
        data[size++] = value;
        return true;
    }

    // Indexing operator overload
    T &operator[](int index)
    {
        return data[index];  // No bounds checking
    }

    // Const version of indexing operator
    const T &operator[](int index) const
    {
        return data[index];
    }
};


template <typename T>
void delete_dynamic_array(dynamic_array<T>* arr)
{
    if (arr)
    {
        free(arr->data);
        delete arr;
    }
}


int main()
{
    dynamic_array<int> arr(5);

    for (int i = 0; i < 15; i++)
    {
        if (!arr.add(i))
        {
            std::cout << "Failed to add element " << i << "\n";
            break;
        }
    }

    for (int i = 0; i < arr.size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}


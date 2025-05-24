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




//Linked List //

template <typename T>
struct linked_list {
    T* first;
    T* last;
};

template <typename T>
struct node {
    T data;
    node<T>* next;
};

/**
 * Creates a new linked list.
 *
 * @tparam T The type of the data that will be stored in the list.
 * @return A pointer to the new linked list.
 */
template <typename T>
linked_list<T> *new_linked_list()
{
    linked_list<T> *list = (linked_list<T> *) malloc(sizeof(linked_list<T>));
    list->first = NULL;
    list->last = NULL;
    return list;
}

/**
 * Delete a linked list.
 *
 * @tparam T The type of the data that will be stored in the list.
 * @param list A pointer to the linked list to delete.
 */
template <typename T>
void delete_linked_list(linked_list<T> *list)
{
    node<T> *current = list->first;
    while (current != NULL)
    {
        node<T> *next = current->next;
        // Clear data from node
        current->next = NULL;
        free(current);
        current = next;
    }
    // Clear old data from list
    list->first = NULL;
    list->last = NULL;
    free(list);
}

/**
 * Print all nodes in the linked list.
 *
 * @tparam T The type of the data that will be stored in the list.
 * @param list A pointer to the linked list to print.
 */
template <typename T>
void print_linked_list(linked_list<T> *list)
{
    node<T> *current = list->first;
    while (current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void add_node(linked_list<T> *list, T data)
{
    node<T> *new_node = (node<T> *) malloc(sizeof(node<T>));
    new_node->data = data;
    new_node->next = NULL;
    if (list->first == NULL)
    {
        list->first = new_node;
        list->last = new_node;
    }
    else
    {
        list->last->next = new_node;
        list->last = new_node;
    }
}

template <typename T>
void remove_node(linked_list<T> *list, node<T> *node)
{
    // Check if we are removing the first node.
    if (list->first == node)
    {
        // Set first to the 2nd node, if it exists
        list->first = node->next;
    }

    // Similarly, check for removing the last node
    if (list->last == node)
    {
        // Will this work?
        list->last = node->next;
    }

    // Find the previous node
    node<T> *current = list->first;
    while (current != NULL)
    {
        // The previous node has the node as its next
        if (current->next == node)
        {
            // Skip the next node
            current->next = node->next;
            break;
        }
        current = current->next;
    }

    // Clear data from node
    node->next = NULL;
    free(node);
}
#include "utilities.h"
#include "splashkit.h"
#include <iostream>
#include <cstdlib>  // for realloc, malloc, free

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
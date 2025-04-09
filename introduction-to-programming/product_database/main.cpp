#include "utilities.h"
#include "splashkit.h"

const int MAX_PRODUCTS = 100;

//create product struct
typedef struct
{
    string name;
    double cost;
    double price;
    int quantity;
} product;

//create store struct
typedef struct
{
    product products[MAX_PRODUCTS];
    int products_number;
    int sales;
    double profit;
} store_data;


//create a search function
int search(store_data &store, string term) {
    // ask user for the search term
    string search_term = to_lowercase(term);
    
    // track the indexes of matched produts 
    strings_list matched_indexes = {{},0};

    // look through all the products array
    for (int i = 0; i < store.products_number; i++)
    {
        
        // check if any products contains the search term
        if (to_lowercase(store.products[i].name).find(search_term) != string::npos)
        {
            //add the index matched to the list
            push_string(matched_indexes, store.products[i].name);
        }
        
    }
    if (matched_indexes.size == 0)
    {
        printf("No products found with that description");
        return -1;
    } else
    {
        // display the list with the tracked products
        print_list_string(matched_indexes);
        // asks the user to choose a number from the list
        int option = read_integer("Enter the number of the product you want to choose: ");
        
        // return the number 
        return option - 1;
    }
}

// adds a new product and adds it to the store
void add_product(store_data &store) {
    string name =read_string("Enter the name of the name of the product");
    int product_index = search(store, name);
    
    // check if the product already exists
    if (product_index == -1)
    {
        double cost = read_double("Enter the cost:");
        double price = read_double("Enter the sale price:");
        double profit = price - cost;
        //creates the new product
        product new_product = {name, cost, price,1};
        //adds the product to the store
        store.products[store.products_number] = new_product;
        //adds the profit to the store
        write_line("Product added!");
    } else
    {
        write_line("The following product already exists:");
        write_line("- " + store.products[product_index].name);
        string ans = read_string("Do you want to add one? [yes / no]: ");
        // checks if the customer wants to increase the quantity of the existed product
        if ( to_lowercase(ans) == "yes")
        {
            double profit = price - cost;
             
            store.products[product_index].quantity++;
            write_line("Done!");
        }
        write_line("Bye bye then!");
    }
}

int main() {
    // Your code goes here
    product house_move = {"House Move", 70, 140, 1};
    product business_move = {"business Move", 70, 140, 1};
    store_data store = {{house_move}, 1, 140,70};

    store.products[0] = house_move;
    store.products[1] = business_move;
    store.products_number += 2;
    
    int chosen_index = search(store);
    write_line(store.products[chosen_index].name);

    return 0;
}

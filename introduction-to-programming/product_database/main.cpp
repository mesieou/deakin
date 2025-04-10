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
    int type_products_quantity;
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
    for (int i = 0; i < store.type_products_quantity; i++)
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
    if (product_index != -1)
    {
        double cost = read_double("Enter the cost:");
        double price = read_double("Enter the sale price:");
        int quantity = read_integer("Quantity:");
        
        //creates the new product
        product new_product = {name, cost, price,quantity};
        //adds the product to the store
        store.products[store.type_products_quantity] = new_product;
        write_line("Product added!");
    } else
    {
        write_line("The following product already exists:");
        write_line("- " + store.products[product_index].name);
        string ans = read_string("Do you want to add more to the stock? [yes / no]: ");
        
        // checks if the customer wants to increase the quantity of the existed product
        if ( to_lowercase(ans) == "yes")
        {
            int quantity = read_integer("Quantity:");
            
            //adds more products of the same category
            store.products[product_index].quantity += quantity;
            
            write_line("Done!");
        }
        write_line("Bye bye then!");
    }
}

void print_menu()
{
    printf("\nMenu\n");
    printf("1. Add a new product\n");
    printf("2. Delete a product\n");
    printf("3. Update a product\n");
    printf("4. Sell a product\n");
    printf("5. Quit\n");
    
}

//todo: add populate_array here
store_data initialise_the_store() {
    write_line("Creating your store...");
    store_data store = {{},0, 0,0};
    
    int size = read_integer("How many different products you would like to enter?");
    
    //checks the user do not initialise the store with more than the quantity of products allowed(100)
    while (size > MAX_PRODUCTS)
    {
        write_line("Sorry the max number is 20");
        size = read_integer("How many different products you would like to enter?");
    }
    
    while (size < 0)
    {
        write_line("Only positive numbers allowed.");
        size = read_integer("How many different products you would like to enter?");
    } 
    
    //setting the products quantity of the store
    store.type_products_quantity = size;
    
    // creating all the products
    for (int i = 0; i < store.type_products_quantity; i++)
    {
        printf("Product %d:\n", i + 1);
        string name = read_string("Name:");
        double cost = read_double("Cost:");
        double price = read_double("Sale Price:");
        int quantity = read_integer("Quantity:");

        //create the product
        product item = {name, cost, price, quantity};

        //save the product in the store
        store.products[i] = item;
    }
    return store;
}

int main() {
    // asks customer the initial state of the store
    store_data store = initialise_the_store();
    
    int option;
    do
    {
        
        print_menu();
        option = read_integer("Enter a number:");
        switch (option)
        {
        case 1:
            add_product(store);
            break;
        // case 2:
        //     remove_at_index(data);
        //     break;
        // case 3:
        //     print(data);
        //     break;
        // case 4:
        //     calculate_stats(data);
        //     break;
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

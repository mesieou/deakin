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
    double sales;
    double profit;
} store_data;

void print_list_products(store_data data)
{
    write_line("");
    printf("List of Products:\n");
    for (int i = 0; i < data.type_products_quantity; i++)
    {
        printf("%d: %s (Qty: %d)\n", i + 1, data.products[i].name.c_str(), data.products[i].quantity);

    }
}

void print_matched_products(int matched_indexes[], int matches, store_data store)
{
    for (int i = 0; i < matches; i++) {
        int actual_index = matched_indexes[i];
        printf("%d: %s (Qty: %d)\n", actual_index + 1, store.products[actual_index].name.c_str(), store.products[actual_index].quantity);
    }
}

//create a search function
int search(store_data &store, string term) {
    printf("Searching product...\n");
    // ask user for the search term
    string search_term = to_lowercase(term);
    
    // track the indexes of matched produts 
    int matched_indexes[MAX_PRODUCTS];
    int matches = 0;

    // look through all the products array
    for (int i = 0; i < store.type_products_quantity; i++)
    {
        // check if any products contains the search term
        if (to_lowercase(store.products[i].name).find(search_term) != string::npos)
        {
            //add the index matched to the list
            matched_indexes[matches] = i;
            matches++;
        }
        
    }
    if (matches == 0)
    {
        printf("No products found with that description\n");
        return -1;
    } else
    {
        write_line("Found these products already in your stock:");

        // display the list with the tracked products
        print_matched_products(matched_indexes, matches, store);

        // asks the user to choose a number from the list
        int option = read_integer("Which one?: ", 1, store.type_products_quantity);
        
        // return the number 
        return option - 1;
    }
}

// adds a new product and adds it to the store
void add_product(store_data &store) {
    string name =read_string("New product name: ");
    int product_index = search(store, name);
    
    
    // check if the product already exists or exceeds the capacity
    if (product_index == -1 && store.type_products_quantity < MAX_PRODUCTS)
    {
        write_line("");
        double cost = read_double("Enter the cost:");
        double price = read_double("Enter the sale price:");
        int quantity = read_integer("Quantity:");
        write_line("");
        
        //creates the new product
        product new_product = {name, cost, price,quantity};
        //adds the product to the store
        store.products[store.type_products_quantity] = new_product;
        
        store.type_products_quantity++;
        write_line("Product added!");
        write_line("");
    } else
    {
        int quantity = read_integer("How many more to add:");
        
        //adds more products of the same category
        store.products[product_index].quantity += quantity;
        write_line("Done!");
    }
}

void print_menu()
{
    printf("\nMenu\n");
    printf("1. Add a new product\n");
    printf("2. Delete a product\n");
    printf("3. Update a product\n");
    printf("4. Sell a product\n");
    printf("5. List all my products\n");
    printf("6. Sales and profits report\n");
    printf("7. Quit\n"); 
}

// asks the customer and deletes a product of the store
void remove(store_data &store) 
{
    string name =read_string("New product name: ");
    // searches all the products in stock and ask the user to select one
    int index = search(store, name);

    //deletes the item
    store.products[index] = store.products[store.type_products_quantity - 1];

    //reduces the number of products in the store
    store.type_products_quantity--;
}

// asks the customer and updates a product of the store
void edit(store_data &store) 
{
    string name =read_string("Edit product name: ");
    
    // searches all the products in stock and ask the user to select one
    int index = search(store, name);
    
    if (index == -1)
    {
        write_line("Product not found. Can't edit.");
        return;
    }
    // Edit the item
    string new_name = read_string("New Name: ");
    double cost = read_double("New Cost: ");
    double price = read_double("New Sale Price: ");
    int quantity = read_integer("New Quantity: ");
    write_line(store.products[index].name);  
    store.products[index] = {new_name, cost, price, quantity};

    write_line("Product updated successfully!");
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

void sell(store_data &store) {
    string name =read_string("Product name: ");
    
    // searches all the products in stock and ask the user to select one
    int index = search(store, name);
    
    // checks if no product was found
    if (index == -1) {
        write_line("Product not found. Can't complete sale.");
        return;
    }
    
    // gets the quantity sold by the user
    int quantity = read_integer("Sold quantity:");

    if (store.products[index].quantity < quantity)
    {
        printf("Sorry not enough items of %s to sell\n", store.products[index].name.c_str());
        return;
    } else if (store.products[index].quantity == quantity)
    {
       printf("Produt %s just had enough quantity. All sold!, you might want to order more!\n", store.products[index].name.c_str());
    }
    
    //updated the stock of the store
    store.products[index].quantity -= quantity;

    // calculates sales
    double sales = store.products[index].price * quantity;
    double cost = store.products[index].cost * quantity;

    //calculate profit
    double profit = sales - cost;

    //update the sales and profits
    store.sales += sales;
    store.profit += profit;
}

void statistics(store_data &store) {
    
    double total_stock_value = 0;
    int low_stock_products = 0;

    // loops through all the products in the store
    for (int i = 0; i < store.type_products_quantity; i++)
    {
        //calculates and adds the value of each product
        total_stock_value += store.products[i].quantity * store.products[i].cost;
        
        //check which products have low stock
        if (store.products[i].quantity < 10)
        {
            low_stock_products++;
        }
    }

    //display all the statistics
    write_line("----------------");
    printf("Total sales: %.2f\n", store.sales);
    printf("Total profit: %.2f\n", store.profit);
    printf("Number of products: %d\n", store.type_products_quantity);
    printf("Total value of stock: %.2f\n", total_stock_value);
    printf("Number of products with less than 10 items: %d\n", low_stock_products);
}

int main() {
    // asks customer the initial state of the store
    store_data store = initialise_the_store();
    
    //shows the user with the list of products in the store.
    print_list_products(store);
    
    int option;
    do
    { 
        print_menu();
        option = read_integer("Enter a number:");

        switch (option)
        {
            case 1:
            //adds the product to the store
            add_product(store);
            //shows the user with the list of products in the store.
            print_list_products(store);
            break;
            case 2:
            //removes the product from the store
            remove(store);
            //shows the user with the list of products in the store.
            print_list_products(store);
            break;
        case 3:
            //removes a product from the store
            edit(store);
            print_list_products(store);
            break;
        case 4:
            //sells a product from the store
            sell(store);
            break;
        case 5:
            //display all the products of the store
            print_list_products(store);
            break;
        case 6:
            //display sales, profits and more statistics from the store
            statistics(store);
            break;
        case 7:
            //exits the program
            printf("bye bye");
            break;
        default:
            write_line("Unknown ooption, please enter a number from 1 to 5.");
            break;
        }
    } while (option != 7);
    return 0;
}

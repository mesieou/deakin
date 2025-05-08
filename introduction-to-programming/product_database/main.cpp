#include "utilities.h"
#include "splashkit.h"
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_PRODUCTS = 100;

typedef struct {
    string name;
    double cost;
    double price;
    int quantity;
} product;

template <typename T>
struct dynamic_array {
    T* data;
    int size;
    int capacity;

    dynamic_array(int initial_capacity = 10)
        : size(0), capacity(initial_capacity) {
        data = (T*)malloc(capacity * sizeof(T));
    }

    ~dynamic_array() {
        free(data);
    }

    void push_back(T value) {
        if (size >= capacity) {
            capacity *= 2;
            data = (T*)realloc(data, capacity * sizeof(T));
        }
        data[size++] = value;
    }

    void remove_at(int index) {
        if (index >= 0 && index < size) {
            data[index] = data[size - 1];
            size--;
        }
    }

    T& operator[](int index) {
        return data[index];
    }
};

typedef struct {
    dynamic_array<product> products;
    double sales;
    double profit;
} store_data;

void print_list_products(store_data &data) {
    write_line("\nList of Products:");
    for (int i = 0; i < data.products.size; i++) {
        printf("%d: %s (Qty: %d)\n", i + 1, data.products[i].name.c_str(), data.products[i].quantity);
    }
}

void print_matched_products(int matched_indexes[], int matches, store_data &store) {
    for (int i = 0; i < matches; i++) {
        int actual_index = matched_indexes[i];
        printf("%d: %s (Qty: %d)\n", actual_index + 1, store.products[actual_index].name.c_str(), store.products[actual_index].quantity);
    }
}

int search(store_data &store, string term) {
    printf("Searching product...\n");
    string search_term = to_lowercase(term);

    int matched_indexes[MAX_PRODUCTS];
    int matches = 0;

    for (int i = 0; i < store.products.size; i++) {
        if (to_lowercase(store.products[i].name).find(search_term) != string::npos) {
            matched_indexes[matches++] = i;
        }
    }

    if (matches == 0) {
        printf("No products found with that description\n");
        return -1;
    }

    write_line("Found these products already in your stock:");
    print_matched_products(matched_indexes, matches, store);
    int option = read_integer("Which one?: ", 1, matches);
    return matched_indexes[option - 1];
}

void add_product(store_data &store) {
    string name = read_string("New product name: ");
    int product_index = search(store, name);

    if (product_index == -1) {
        double cost = read_double("Enter the cost:");
        double price = read_double("Enter the sale price:");
        int quantity = read_integer("Quantity:");
        store.products.push_back({name, cost, price, quantity});
        write_line("Product added!");
    } else {
        int quantity = read_integer("How many more to add:");
        store.products[product_index].quantity += quantity;
        write_line("Done!");
    }
}

void print_menu() {
    printf("\nMenu\n");
    printf("1. Add a new product\n");
    printf("2. Delete a product\n");
    printf("3. Update a product\n");
    printf("4. Sell a product\n");
    printf("5. List all my products\n");
    printf("6. Sales and profits report\n");
    printf("7. Quit\n");
}

void remove_product(store_data &store) {
    string name = read_string("Product name to delete: ");
    int index = search(store, name);
    if (index != -1) {
        store.products.remove_at(index);
        write_line("Product removed.");
    }
}

void edit(store_data &store) {
    string name = read_string("Edit product name: ");
    int index = search(store, name);

    if (index == -1) {
        write_line("Product not found. Can't edit.");
        return;
    }

    string new_name = read_string("New Name: ");
    double cost = read_double("New Cost: ");
    double price = read_double("New Sale Price: ");
    int quantity = read_integer("New Quantity: ");
    store.products[index] = {new_name, cost, price, quantity};
    write_line("Product updated successfully!");
}

store_data initialise_the_store() {
    write_line("Creating your store...");
    store_data store = {dynamic_array<product>(10), 0, 0};

    int size = read_integer("How many different products you would like to enter?");
    while (size > MAX_PRODUCTS || size < 0) {
        write_line("Please enter a valid number between 0 and 100.");
        size = read_integer("How many different products you would like to enter?");
    }

    for (int i = 0; i < size; i++) {
        printf("Product %d:\n", i + 1);
        string name = read_string("Name:");
        double cost = read_double("Cost:");
        double price = read_double("Sale Price:");
        int quantity = read_integer("Quantity:");
        store.products.push_back({name, cost, price, quantity});
    }

    return store;
}

void sell(store_data &store) {
    string name = read_string("Product name: ");
    int index = search(store, name);

    if (index == -1) {
        write_line("Product not found. Can't complete sale.");
        return;
    }

    int quantity = read_integer("Sold quantity:");
    if (store.products[index].quantity < quantity) {
        printf("Sorry not enough items of %s to sell\n", store.products[index].name.c_str());
        return;
    }

    if (store.products[index].quantity == quantity) {
        printf("Product %s just had enough quantity. All sold!\n", store.products[index].name.c_str());
    }

    store.products[index].quantity -= quantity;
    double sales = store.products[index].price * quantity;
    double cost = store.products[index].cost * quantity;
    double profit = sales - cost;

    store.sales += sales;
    store.profit += profit;
}

void statistics(store_data &store) {
    double total_stock_value = 0;
    int low_stock_products = 0;

    for (int i = 0; i < store.products.size; i++) {
        total_stock_value += store.products[i].quantity * store.products[i].cost;
        if (store.products[i].quantity < 10) {
            low_stock_products++;
        }
    }

    write_line("----------------");
    printf("Total sales: %.2f\n", store.sales);
    printf("Total profit: %.2f\n", store.profit);
    printf("Number of products: %d\n", store.products.size);
    printf("Total value of stock: %.2f\n", total_stock_value);
    printf("Number of products with less than 10 items: %d\n", low_stock_products);
}

int main() {
    store_data store = initialise_the_store();
    print_list_products(store);

    int option;
    do {
        print_menu();
        option = read_integer("Enter a number:");

        switch (option) {
            case 1:
                add_product(store);
                print_list_products(store);
                break;
            case 2:
                remove_product(store);
                print_list_products(store);
                break;
            case 3:
                edit(store);
                print_list_products(store);
                break;
            case 4:
                sell(store);
                break;
            case 5:
                print_list_products(store);
                break;
            case 6:
                statistics(store);
                break;
            case 7:
                printf("Bye bye\n");
                break;
            default:
                write_line("Unknown option, please enter a number from 1 to 7.");
                break;
        }
    } while (option != 7);

    return 0;
}

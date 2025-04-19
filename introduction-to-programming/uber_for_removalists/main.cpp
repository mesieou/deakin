#include "utilities.h"
#include "splashkit.h"

//used for time delays
#include <iostream>
#include <chrono>
#include <thread>

//declares the models in advance as they need to be able to be linked with each other
typedef struct booking booking;
typedef struct customer customer;
typedef struct quote quote;


//sets the max number of services 
const int MAX_SERVICES = 100;
const int MAX_BOOKINGS = 100;

// Enum for status
enum status { not_accepted, accepted, completed };

// Service object that holds the information of a service
typedef struct 
{
    string name;
    double price;
    int quantity;
} service;

// Business object that holds the information of all services
typedef struct
{
    service services[MAX_SERVICES];
    int quantity;
} business;

// driver object that hold all the driver information
typedef struct 
{
    string name;
    string email;
    quote* quote[MAX_BOOKINGS];
    booking* booking[MAX_BOOKINGS];
} driver;

// Customer object that hold all the customer information
struct customer 
{
    string name;
    string email;
    quote* quote[MAX_BOOKINGS];
    booking* booking[MAX_BOOKINGS];
};

// Quote object that holds all the quote information
struct quote
{
    customer* customer;
    string pick_up;
    string drop_off;
    service* service;
    double total_price;
    status status;
};

// Booking object that holds all the booking information
struct booking 
{
    quote* quote;
    driver* driver;
    customer* customer;
    string date;
    status status;
};



//formats the start of something new
void new_text_formatted(string text) {
    write_line("-------------");
    write_line(text);
}

//formats the start of something new
void end_text_formatted(string text) {
    write_line(text);
    write_line("");
}

//simulates loading
#include "splashkit.h"

void loading()
{
    string text = "Loading";

    // Print "loading" letter by letter
    for (int i = 0; i < text.length(); i++) {
        write(text[i]);  // Print each character
        delay(100);  // Delay between each letter
    }

    // Print dots after "loading" is done
    for (int i = 0; i < 5; i++) {
        delay(100);  // Delay between each dot
        write(".");  // Print one dot at a time
    }
    
    write_line("");  // Move to the next line after the loading is complete
}


//Create dummy data to test the functions and the program
void create_dummy_data() {
    
    //create a business with 3 services
    new_text_formatted("Creating a business with 3 services");
    business my_business = {
        {
            {"House Move", 100, 2},
            {"Business Move", 150, 2},
            {"Furniture Move", 75, 1}
        },
        3
    };

    //simulates creating one by one
    delay(100);

    //create a customer
    write_line("Creating a customer");
    customer juan = { "Juan", "mesieou@gmail.com"};

    //simulates creating one by one
    delay(100);

    //create 1 driver
    write_line("Creating a driver");
    driver alberto = { "Alberto", "alberto@hotmail.com" };

    //simulates creating one by one
    delay(100);
    
    //create 2 quotes
    write_line("Creating 2 quotes");
    quote first_quote = {
        &juan,
        "44 Sprint St, Melbourne vic 3000",
        "57 Aberdenn St, Fitzroy vic 3300",
        &my_business.services[0],
        450,
        not_accepted
    };
    quote second_quote = {
        &juan,
        "44 Sprint St, Melbourne vic 3000",
        "88 expenset St, Albert Park vic 3100",
        &my_business.services[2],
        300,
        accepted
    };

    //simulates creating one by one
    delay(100);

    //create 2 bookings
    write_line("Creating 2 bookings");
    booking first_booking = {
        &first_quote,
        &alberto,
        &juan,
        "03/05/2025",
        accepted
    };
    booking secong_booking = {
        &second_quote,
        &alberto,
        &juan,
        "06/12/2025",
        accepted
    };

    //simulates creating one by one
    delay(100);

    //assign the quotes to the customer and driver 
    write_line("Assigning the quotes to the customer and driver");
    juan.quote[0] = &first_quote;
    juan.quote[1] = &second_quote;
    alberto.quote[0] = &first_quote;
    alberto.quote[1] = &second_quote;

    //simulates creating one by one
    delay(100);
    
    //assign the quotes to the customer and driver 
    write_line("Assigning the bookings to the customer and driver");
    juan.booking[0] = &first_booking;
    juan.booking[1] = &secong_booking;
    alberto.booking[0] = &first_booking;
    alberto.booking[1] = &secong_booking;

    loading();
    end_text_formatted("All done!");
}

//Customer fuctions
  //get_quote()
    //read_pick_up
    //read_drop_off
    //read_service
    //calculate price
    //diplay price
  //book_service()
    //read_date
    //send_booking_to_driver
    //new_booking
    //send_message_notificaton
    //display_booking
  //see_all_bookings

//driver functions
  //get_quotes(not accepted)
  //get_jobs(not completed)
  //read_option
  //accept_quotes()
  //complete_job()
  //show_job(accepted)
  //display_quotes(not accepted)
  //display_jobs(not complete)

// Customer logic manager 
  //logic to act
    //get a quote
    //book a service
    //See my bookings

// Driver logic manager
  //check_requests
  //list_jobs
  //mark as completed

//Asks the user whether they are a driver or a customer
int read_interface(int option) {
    //shows the initial menu
    write_line("1 - Customer");
    write_line("2 - Drive");
    write_line("3 - Exit");

    //gets the user option
    option = read_integer("Select 1 or 3:");
    return option;
}

int main() {
    // Initialise  dummy data
    create_dummy_data();

    // driver or customer logic
    new_text_formatted("Welcome to Uber for Removalists");
    int option;

    do
    {   
        //Asks the user whether they are a driver or a customer
        option = read_interface(option);

        //Initial menu to choose customer or driver interface
        switch (option)
        {
        case 1:
            // customer_logic_manager;
            break;
        case 2:
            // driver_logic_manager;
            break;
        case 3:
            end_text_formatted("Bye Bye");
            break;
        default:

            end_text_formatted("Not a valid entry. Please enter a number from 1 to 3.");
            break;
        }
    } while (option !=3);
    
      //show custtomer_logic_manager
      //show driver_logic_manager
    return 0;
}

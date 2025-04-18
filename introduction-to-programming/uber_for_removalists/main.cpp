#include "utilities.h"
#include "splashkit.h"

//used for time delays
#include <iostream>
#include <chrono>
#include <thread>

//declares the models in advance as they need to be able to be linked with each other
typedef struct booking booking;
typedef struct customer customer;

//sets the max number of services 
const int MAX_SERVICES = 100;
const int MAX_BOOKINGS = 100;

// Enum for status
enum status { not_accepted, accepted };

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
    booking* booking[MAX_BOOKINGS];
} driver;

// Customer object that hold all the customer information
struct customer 
{
    string name;
    string email;
    booking* booking[MAX_BOOKINGS];
};

// Quote object that holds all the quote information
typedef struct 
{
    customer* customer;
    string pick_up;
    string drop_off;
    service* service;
    double total_price;
    status quote;
} quote;

// Booking object that holds all the booking information
struct booking 
{
    quote* quote;
    driver* driver;
    string date;
    enum status {not_accepted, Accepted};
};



//formats the start of something new
void new_text_formatted(string text) {
    write_line("-------------");
    write_line(text);
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

    write_line("Creating a customer");
    
    //create a customer
    customer juan = { "Juan", "mesieou@gmail.com"};

    //create 1 driver
    driver alberto = { "Alberto", "alberto@hotmail.com" };
    
    //create 2 quotes
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

    //create 2 bookings
    //assing the quotes
    //assign the bookings to the customer and driver 
    loading();
    
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

int main() {
    // Initialise  dummy data
    create_dummy_data();
    // driver or customer logic
      //show custtomer_logic_manager
      //show driver_logic_manager
    return 0;
}

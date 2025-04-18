#include "utilities.h"
#include "splashkit.h"

//used for time delays
#include<unistd.h>
unsigned int microsecond = 1000000;


//sets the max number of services 
const int MAX_SERVICES = 100;
const int MAX_BOOKINGS = 100;



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


// Booking object that holds all the booking information
typedef struct 
{
    quote quote;
    driver driver;
    string date;
    enum status {not_accepted, Accepted};
} booking;

// Quote object that holds all the quote information
typedef struct 
{
    customer customer;
    string pick_up;
    string drop_off;
    service service;
    double total_price;
    enum status {not_accepted, Accepted};
} quote;

// Create the Driver struct
typedef struct 
{
    string name;
    string email;
    booking booking[MAX_BOOKINGS];
} driver;

// Customer object that hold all the customer information
typedef struct 
{
    string name;
    string email;
    booking booking[MAX_BOOKINGS];
} customer;

void new_text_formatted(string text) {
    write_line("-------------");
    write_line(text);
}

void loading() {
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono;
    printf("loading");

    for (int i = 0; i < 5; i++)
    {
        printf(".");
        usleep(0.3 * microsecond);
    }
    
}
//Create dummy data to test the functions and the program
void create_dummy_data() {
    //create services
    new_text_formatted("Creating Services")

    //create 1 customer
    //create 1 driver
    //create 3 quotes
    //create 2 bookings
      //assing the quotes
      //assign the bookings to the customer and driver 
    
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
    
    // driver or customer logic
      //show custtomer_logic_manager
      //show driver_logic_manager
    return 0;
}

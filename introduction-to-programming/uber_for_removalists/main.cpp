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
typedef struct driver driver;

//sets the max number of services 
const int MAX_SERVICES = 100;
const int MAX_BOOKINGS = 100;
const int MAX_QUOTES = 100;
const int MAX_DRIVERS = 10;
const int MAX_CUSTOMERS = 100;

//sets the travel cost per minute to calculate quotes
const double TRAVEL_COST_PER_MINUTE = 2.33;

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
struct business
{
    service services[MAX_SERVICES];
    driver* drivers[MAX_DRIVERS];
    customer* customers[MAX_CUSTOMERS];
    booking* bookings[MAX_BOOKINGS];
    quote* quotes[MAX_QUOTES];
    int number_of_services = 0;
    int quote_count = 0;
    int booking_count = 0;
    int driver_count = 0;
    int customer_count = 0;
};

// driver object that hold all the driver information
struct driver 
{
    string name;
    string email;
    quote* quotes[MAX_BOOKINGS];
    booking* bookings[MAX_BOOKINGS];
    int quote_count = 0;
    int booking_count = 0;
} ;

// Customer object that hold all the customer information
struct customer 
{
    string name;
    string email;
    quote* quotes[MAX_BOOKINGS];
    booking* bookings[MAX_BOOKINGS];
    int quote_count = 0;
    int booking_count = 0;
};

// Quote object that holds all the quote information
struct quote
{
    customer* customer;
    string pick_up;
    string drop_off;
    service* service;
    int total_price;
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
    write_line("-----------------------------------------------");
    write_line(text);
}

//formats the start of something new
void end_text_formatted(string text) {
    write_line(text);
    write_line("");
}

//simulates loading
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
business create_dummy_data() {
    
    //create a business with 3 services
    new_text_formatted("Creating a business with 3 services");
    business my_business = {
        {
            {"House Move", 100, 1},
            {"Business Move", 150, 2},
            {"Furniture Move", 75, 3}
        }
    };

    //updates the number of services in the business
    my_business.number_of_services = 3;

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
    juan.quotes[0] = &first_quote;
    juan.quotes[1] = &second_quote;
    alberto.quotes[0] = &first_quote;
    alberto.quotes[1] = &second_quote;
    juan.quote_count += 2;
    alberto.quote_count += 2;

    //simulates creating one by one
    delay(100);
    
    //assign the quotes to the customer and driver 
    write_line("Assigning the bookings to the customer and driver");
    juan.bookings[0] = &first_booking;
    juan.bookings[1] = &secong_booking;
    alberto.bookings[0] = &first_booking;
    alberto.bookings[1] = &secong_booking;
    juan.booking_count += 2;
    alberto.booking_count += 2;

    write_line("Assigning everything to the business");
    //assing the drivers, customers, quotes and bookings to the business
    my_business.bookings[0] = &first_booking;
    my_business.bookings[1] = &secong_booking;
    my_business.quotes[0] = &first_quote;
    my_business.quotes[1] = &second_quote;
    my_business.customers[0] = &juan;
    my_business.drivers[0] = &alberto;

    //updating the counts of everything
    my_business.customer_count += 1;
    my_business.driver_count += 1;
    my_business.booking_count += 2;
    my_business.quote_count += 2;

    
    loading();
    end_text_formatted("All done!");

    //returning the business with all the info
    return my_business;
}

//Customer fuctions
//get_quote()
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
  
// Displays a menu
void display_menu(string options[], int count) {
    //iterates through the options and display each option
    for (int i = 0; i < count; i++)
    {
        write_line( to_string(i + 1) + " - " + options[i]);
    }   
}

// Display services and read service from the user
service read_service( business &uber) {
    write_line("Service selection");
    // display all the services
    for (int i = 0; i < uber.number_of_services; i++)
    {
        write_line(to_string(i + 1) + " - " + uber.services[i].name);
    }

    //Display the services to the customer and ask user to choose
    int option = read_integer("Select 1 to " + to_string(uber.number_of_services) + ":", 1, uber.number_of_services);
    
    //creates a new service with the number selected
    service service_chosen = uber.services[option - 1];
    
    //return the service
    return service_chosen;
}
int calculate_price(int mins, int base) {
    //calculate travel cost
    int travel_cost = mins * TRAVEL_COST_PER_MINUTE;
    int total_cost = travel_cost + base;

    return total_cost;
}

int calculate_time_between_addresses(string pick_up, string drop_off) {
    // Simulates the calculation of distance between pick up and drop off 
    int mins = rnd(5, 180);  // returns a random integer from 1 to 50 inclusive
    return mins;
}

// display the quote to the customer
void display_quote(int base, int mins, int total) {
    new_text_formatted("Quote details:");
    write_line("Base Cost: " + to_string(base));
    write_line("Tracel Cost: " + to_string(mins * TRAVEL_COST_PER_MINUTE));
    write_line("");
    write_line("Total: " + to_string(total));
    write_line("");
}
//create a new quote
quote create_quote(customer &user, string pick_up, string drop_off, service service, int price) {
    //creates the quote
    quote new_quote = {
        &user,
        pick_up,
        drop_off,
        &service,
        price,
        not_accepted
    };
    //assings the bookings to the customer and the driver
    user.quotes[user.quote_count] = &new_quote;
    
    //updates the quotes count of the user
    user.quote_count++;

    return new_quote;
}

//creates a new booking
booking create_booking(quote &quote, driver &driver, customer &customer, string date) {
   // creates the booking
    booking new_boooking = {
        &quote,
        &driver,
        &customer,
        date,
        not_accepted
    };
    
    //assings the bookings to the customer and the driver
    customer.bookings[customer.booking_count] = &new_boooking;
    driver.bookings[driver.booking_count] = &new_boooking;

    //updates the bookings count of the customer and driver
    customer.booking_count++;
    driver.booking_count++;
    
    return new_boooking;
}

void display_booking(booking booking) {
    write_line("");
    write_line("Date: " + booking.date);
    write_line("Pick Up: " + booking.quote->pick_up);
    write_line("Drop Up: " + booking.quote->drop_off);
    write_line("Service: " + booking.quote->service->name);
    write_line("Price: " +  to_string(booking.quote->total_price));
    write_line("Driver: " +  booking.driver->name);
}
// Customer logic manager 
void logic_manager(string options[], int options_length,  business &uber) {
    int option;

    //Greets the customer with a line
    new_text_formatted("Welcome back!");

    //Redirects to the correct function based on the user selection
    do
    {   
        //shows the initial menu
        display_menu(options, options_length);
        
        //Asks the customer what they want to do
        option = read_integer("Select 1 to " + to_string(options_length) + ":", 1, options_length);
        //Redirects to the correct interface based on the user selection
        switch (option)
        {
        //Creates a quote to the user
        case 1:
        {
            booking new_booking;

            //Gets the pick up from the user
            string pick_up = read_string("Pick up:");
           
            //Gets the drop off from the user
            string drop_off = read_string("Drop off:");
 
            //read_service
            service chosen_service = read_service(uber);

            //base price
            int base_price = chosen_service.price;

            //calculates distance
            int travel_time_in_mins = calculate_time_between_addresses(pick_up, drop_off);

            //calculate price
            int total_price = calculate_price(travel_time_in_mins, base_price);

            //create quote
            quote new_quote = create_quote(*uber.customers[0], pick_up, drop_off, chosen_service, total_price);
            
            //updates the quote count of the business
            uber.quote_count++;

            //diplay quote
            display_quote(base_price, travel_time_in_mins, total_price);

            // ask the user if they would like to accept the quote
            string ans  =read_string("Would you like to book this quote [y | n]: ");

            // logic to book or not the quote based on users input
            if (to_lowercase(ans) == "y" || to_lowercase(ans) == "yes")
            {
                string date = read_string("Service_date: ");
                //creates the new booking
                new_booking = create_booking(new_quote, *uber.drivers[0], *uber.customers[0], date);
                
                //assings the booking to the business
                uber.bookings[uber.booking_count] = &new_booking;

                //updates the booking count of the business, customer and driver
                uber.booking_count++;
                uber.customers[0]->booking_count++;
                uber.drivers[0]->booking_count++;

            }
            
            // display the booking
            display_booking(new_booking);

            //ask user
            break;
        }
        case 2:
            //Books a service
            break;
        case 3:
            //Show all the bookings
            break;
        case 4:
            //exits and displays a message to the user
            end_text_formatted("Bye Bye");
            break;
        default:
            end_text_formatted("Not a valid entry. Please enter a number from 1 to 3.");
            break;
        }
    } while (option !=4);
}

//Asks the user whether they are a driver or a customer
int read_interface(int option) {
    int options_length = 3;
    //initialises the array of options
    string options[] = {"Customer", "Driver", "Exit"};
    
    //shows the initial menu to the user
    display_menu(options, options_length);

    //gets the user option
    option = read_integer("Select 1 to " + to_string(options_length) + ":", 1 , options_length);
    return option;
}

int main() {
    // Initialise  dummy data
    business uber = create_dummy_data();

    int option;
    
    do
    {   
        //number of options in the general menu
        int options_length = 3;
        
        //initialise the customer menu options in an array
        int customer_options_length = 4;
        
        //initialise the driver menu options in an array
        int driver_options_length = 4;
        
        //initialse the driver and customer arrays that holds the options of the menu
        string customer_options[] = {"Get a quote", "Book a service", "See all my bookings", "Exit"};
        string driver_options[] = {"Check Requests", "Mark jobs as completed", "See all my jobs", "Exit"};

        // driver or customer logic
        new_text_formatted("Welcome to Uber for Removalists");
        
        //Asks the user whether they are a driver or a customer
        option = read_interface(options_length);

        //Redirects to the correct interface based on the user selection
        switch (option)
        {
        case 1:
            //show custtomer_logic_manager
            logic_manager(customer_options, customer_options_length, uber);
            break;
        case 2:
            //show driver_logic_manager
            logic_manager(driver_options, driver_options_length, uber);
            break;
        case 3:
            //exit the menu
            end_text_formatted("Bye Bye");
            break;
        default:

            end_text_formatted("Not a valid entry. Please enter a number from 1 to 3.");
            break;
        }
    } while (option !=3);
    
    return 0;
}

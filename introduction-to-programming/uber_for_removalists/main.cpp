#include "utilities.h"
#include "splashkit.h"
#include <curl/curl.h>
#include "json.hpp"

//used for time delays
#include <iostream>
#include <chrono>
#include <thread>

// Constants
const int MAX_SERVICES = 100;
const int MAX_BOOKINGS = 100;
const int MAX_QUOTES = 100;
const int MAX_DRIVERS = 10;
const int MAX_CUSTOMERS = 100;
const double TRAVEL_COST_PER_MINUTE = 2.33;
const string GOOGLE_MAPS_API_KEY = "AIzaSyD6kxT0Q93AFEkQdoRW2XKMHk1iznFfw2U"; // Replace with your actual API key

// Enum
enum status { not_accepted, accepted, completed };

// Service
struct service {
    string name;
    double price;
    int quantity;
};

struct ServiceWithIndex {
    service selected_service;
    int index;
};

// Route information from Google Maps API
struct route_info {
    double distance_km;
    int duration_mins;
    string polyline; // Encoded route path
};

// Quote
struct quote {
    int customer_id;
    string pick_up;
    string drop_off;
    int service_index;
    int total_price;
    status status;
    route_info route; // Added for route visualization
};

// Booking
struct booking {
    int quote_index;
    int driver_id;
    int customer_id;
    string date;
    status status;
};

// Driver
struct driver {
    string name;
    string email;
    int booking_indexes[MAX_BOOKINGS];
    int booking_count = 0;
};

// Customer
struct customer {
    string name;
    string email;
    int quote_indexes[MAX_QUOTES];
    int booking_indexes[MAX_BOOKINGS];
    int quote_count = 0;
    int booking_count = 0;
};

// Business
struct business {
    service services[MAX_SERVICES];
    driver drivers[MAX_DRIVERS];
    customer customers[MAX_CUSTOMERS];
    booking bookings[MAX_BOOKINGS];
    quote quotes[MAX_QUOTES];
    int number_of_services = 0;
    int quote_count = 0;
    int booking_count = 0;
    int driver_count = 0;
    int customer_count = 0;
};

// Forward declarations of functions
quote create_quote(int customer_index, string pick_up, string drop_off, int service_index, int price);
booking create_booking(int quote_index, int driver_index, int customer_index, string date, business &my_business);
ServiceWithIndex read_service(business &uber);
int calculate_price(int mins, int base);
bool show_driver_confirmation_popup(const quote &q, const service &s);
route_info get_route_info(const string &origin, const string &destination);
bool show_quote_visualization(const quote &q, const service &s);
bool show_quote_acceptance_popup(const quote &q, const service &s);
void checks_quote_acceptance_and_create_booking(business &uber, int customer_index, int new_quote_index);

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
    // Create a business with 3 services
    new_text_formatted("Creating a business with 3 services");
    business my_business = {
        {
            {"House Move", 100, 1},
            {"Business Move", 150, 2},
            {"Furniture Move", 75, 3}
        }
    };
    my_business.number_of_services = 3;

    delay(100);

    // Create a customer
    write_line("Creating a customer");
    customer juan = { "Juan", "mesieou@gmail.com" };
    int customer_index = my_business.customer_count;
    my_business.customers[customer_index] = juan;
    my_business.customer_count++;

    delay(100);

    // Create a driver
    write_line("Creating a driver");
    driver alberto = { "Alberto", "alberto@hotmail.com" };
    int driver_index = my_business.driver_count;
    my_business.drivers[driver_index] = alberto;
    my_business.driver_count++;

    delay(100);

    // Create 2 quotes
    write_line("Creating 2 quotes");

    quote first_quote = {
        customer_index,
        "44 Sprint St, Melbourne vic 3000",
        "57 Aberdenn St, Fitzroy vic 3300",
        0, // service index
        450,
        accepted    
    };

    quote second_quote = {
        customer_index,
        "44 Sprint St, Melbourne vic 3000",
        "88 expenset St, Albert Park vic 3100",
        2, // service index
        300,
        accepted
    };

    int first_quote_index = my_business.quote_count++;
    int second_quote_index = my_business.quote_count++;
    my_business.quotes[first_quote_index] = first_quote;
    my_business.quotes[second_quote_index] = second_quote;

    // Update customer with quote indexes
    my_business.customers[customer_index].quote_indexes[0] = first_quote_index;
    my_business.customers[customer_index].quote_indexes[1] = second_quote_index;
    my_business.customers[customer_index].quote_count = 2;

    delay(100);

    // Create 2 bookings
    write_line("Creating 2 bookings");

    booking first_booking = {
        first_quote_index,
        driver_index,
        customer_index,
        "03/05/2025",
        accepted
    };

    booking second_booking = {
        second_quote_index,
        driver_index,
        customer_index,
        "06/12/2025",
        accepted
    };

    int first_booking_index = my_business.booking_count++;
    int second_booking_index = my_business.booking_count++;
    my_business.bookings[first_booking_index] = first_booking;
    my_business.bookings[second_booking_index] = second_booking;

    // Update customer and driver with booking indexes
    my_business.customers[customer_index].booking_indexes[0] = first_booking_index;
    my_business.customers[customer_index].booking_indexes[1] = second_booking_index;
    my_business.customers[customer_index].booking_count = 2;

    my_business.drivers[driver_index].booking_indexes[0] = first_booking_index;
    my_business.drivers[driver_index].booking_indexes[1] = second_booking_index;
    my_business.drivers[driver_index].booking_count = 2;

    delay(100);

    loading();
    end_text_formatted("All done!");

    return my_business;
}

// Displays a menu
void display_menu(string options[], int count) {
    //iterates through the options and display each option
    for (int i = 0; i < count; i++)
    {
        write_line( to_string(i + 1) + " - " + options[i]);
    }   
}

// Display services and read service from the user
ServiceWithIndex read_service(business &uber) {
    write_line("Service selection");

    // Display all services
    for (int i = 0; i < uber.number_of_services; i++) {
        write_line(to_string(i + 1) + " - " + uber.services[i].name);
    }

    // Ask the user to choose a service
    int option = read_integer("Select 1 to " + to_string(uber.number_of_services) + ": ", 1, uber.number_of_services);

    // Return the service and its index
    ServiceWithIndex result = { uber.services[option - 1], option - 1 };
    return result;
}

// calculate a quote price with the travel time and base cost
int calculate_price(int mins, int base) {
    //calculate travel cost
    int travel_cost = mins * TRAVEL_COST_PER_MINUTE;
    int total_cost = travel_cost + base;

    return total_cost;
}

// simulates the calculation of time between addressess
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
quote create_quote(int customer_index, string pick_up, string drop_off, int service_index, int price) {
    // Create the quote with reference indexes
    quote new_quote = {
        customer_index,
        pick_up,
        drop_off,
        service_index,
        price,
        not_accepted
    };
    return new_quote;
}

booking create_booking(int quote_index, int driver_index, int customer_index, string date, business &my_business) {
    // Create the booking with reference indexes
    booking new_booking = {
        quote_index,
        driver_index,
        customer_index,
        date,
        accepted
    };

    // Assign the booking to the customer
    customer &c = my_business.customers[customer_index];
    c.booking_indexes[c.booking_count] = my_business.booking_count;
    c.booking_count++;

    // Assign the booking to the driver
    driver &d = my_business.drivers[driver_index];
    d.booking_indexes[d.booking_count] = my_business.booking_count;
    d.booking_count++;

    // Store the booking in the business
    my_business.bookings[my_business.booking_count] = new_booking;
    my_business.booking_count++;

    return new_booking;
}

//maps the status to a string to show:
string status_to_string(status s) {
    switch (s) {
        case not_accepted: return "Not Accepted";
        case accepted: return "Accepted";
        case completed: return "Completed";
        default: return "Unknown";
    }
}

//display one specific bookings
void display_booking(booking curr_booking, business uber) {

    //retrieves the quote associated with the current iteration booking
    quote curr_quote = uber.quotes[curr_booking.quote_index];

    //retrieves the service associated with the current iteration quote
    service curr_service = uber.services[curr_quote.service_index];

    //retrieves the driver associated with the current iteration booking
    driver curr_driver = uber.drivers[curr_booking.driver_id];

    //retrieves the customer associated with the current iteration booking
    customer curr_customer = uber.customers[curr_booking.customer_id];

    //displays all the details to the user
    write_line("");
    write_line("Date: " + curr_booking.date);
    write_line("Pick Up: " + curr_quote.pick_up );
    write_line("Drop Up: " + curr_quote.drop_off );
    write_line("Service: " + curr_service.name);
    write_line("Price: " +  to_string(curr_quote.total_price));
    write_line("Driver: " +  curr_driver.name);
    write_line("Customer: " +  curr_customer.name);
    write_line("Status: " +  status_to_string(curr_booking.status));

    write_line("");
}

// Callback function for CURL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Get route information from Google Maps API
route_info get_route_info(const string &origin, const string &destination) {
    route_info info;
    CURL* curl = curl_easy_init();
    string readBuffer;

    if(curl) {
        char* origin_escaped = curl_easy_escape(curl, origin.c_str(), (int)origin.length());
        char* destination_escaped = curl_easy_escape(curl, destination.c_str(), (int)destination.length());

        string url = "https://maps.googleapis.com/maps/api/directions/json?origin=" +
                     string(origin_escaped) +
                     "&destination=" +
                     string(destination_escaped) +
                     "&key=" + GOOGLE_MAPS_API_KEY;

        curl_free(origin_escaped);
        curl_free(destination_escaped);

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            auto json = nlohmann::json::parse(readBuffer);
            
            // Extract route information
            if(json["status"] == "OK") {
                auto route = json["routes"][0]["legs"][0];
                info.distance_km = route["distance"]["value"].get<double>() / 1000.0;
                info.duration_mins = route["duration"]["value"].get<int>() / 60;
                info.polyline = json["routes"][0]["overview_polyline"]["points"].get<string>();
            }
        }
        curl_easy_cleanup(curl);
    }
    return info;
}

// Show quote visualization window
bool show_quote_visualization(const quote &q, const service &s) {
    window quote_window = open_window("Quote Details", 900, 800);
    delay(200);
    bool decision_made = false;
    bool accepted = false;

    while(!window_close_requested(quote_window) && !decision_made) {
        process_events();
        clear_screen(COLOR_WHITE);

        // Draw map background
        fill_rectangle(COLOR_LIGHT_GRAY, 0, 0, 900, 450);

        // Draw route using polyline
        draw_line(COLOR_BLUE, point_at(100, 250), point_at(800, 250));

        // Draw pickup and dropoff markers
        fill_circle(COLOR_RED, 100, 250, 10);
        fill_circle(COLOR_GREEN, 800, 250, 10);

        // Draw quote details
        draw_text("Quote Details", COLOR_BLACK, "Arial", 28, 20, 500);
        draw_text("Pickup: " + q.pick_up, COLOR_BLACK, "Arial", 18, 20, 540);
        draw_text("Dropoff: " + q.drop_off, COLOR_BLACK, "Arial", 18, 20, 570);
        draw_text("Service: " + s.name, COLOR_BLACK, "Arial", 18, 20, 600);
        
        // Draw price breakdown
        draw_text("Price Breakdown:", COLOR_BLACK, "Arial", 18, 500, 500);
        draw_text("Base Service: $" + to_string(s.price), COLOR_BLACK, "Arial", 16, 500, 530);
        draw_text("Travel Cost: $" + to_string(q.route.duration_mins * TRAVEL_COST_PER_MINUTE), COLOR_BLACK, "Arial", 16, 500, 560);
        draw_text("Total: $" + to_string(q.total_price), COLOR_BLACK, "Arial", 18, 500, 590);

        // Draw route information
        draw_text("Route Information:", COLOR_BLACK, "Arial", 18, 20, 640);
        draw_text("Distance: " + to_string(q.route.distance_km) + " km", COLOR_BLACK, "Arial", 16, 20, 670);
        draw_text("Duration: " + to_string(q.route.duration_mins) + " mins", COLOR_BLACK, "Arial", 16, 20, 700);
        draw_text("Travel Time: " + to_string(q.route.duration_mins) + " minutes", COLOR_BLACK, "Arial", 16, 500, 620);

        // Draw accept button
        fill_rectangle(COLOR_GREEN, 350, 650, 200, 50);
        draw_text("Accept Quote", COLOR_WHITE, "Arial", 18, 400, 665);

        // Draw reject button
        fill_rectangle(COLOR_RED, 350, 710, 200, 50);
        draw_text("Reject Quote", COLOR_WHITE, "Arial", 18, 400, 725);

        if(mouse_clicked(LEFT_BUTTON)) {
            point_2d mouse = mouse_position();
            if(mouse.x >= 350 && mouse.x <= 550 && mouse.y >= 650 && mouse.y <= 700) {
                accepted = true;
                decision_made = true;
                write_line("Quote accepted by customer.");
            }
            if(mouse.x >= 350 && mouse.x <= 550 && mouse.y >= 710 && mouse.y <= 760) {
                accepted = false;
                decision_made = true;
                write_line("Quote rejected by customer.");
            }
        }

        refresh_screen(60);
    }

    close_window(quote_window);
    // Give the OS time to close the window and process events
    delay(200); // 200 ms delay
    process_events();

    return accepted;
}

// Show quote acceptance popup
bool show_quote_acceptance_popup(const quote &q, const service &s) {
    show_quote_visualization(q, s);
    return true; // For now, always return true as we're handling acceptance in the visualization
}

// Modify quote_form to use the new visualization
int quote_form(business &uber, int customer_index) {
    string pick_up = read_string("Pick up:");
    string drop_off = read_string("Drop off:");

    ServiceWithIndex chosen_service = read_service(uber);
    service selected_service = chosen_service.selected_service;
    int service_index = chosen_service.index;

    // Get route information
    route_info route = get_route_info(pick_up, drop_off);
    
    // Calculate price
    int total_price = calculate_price(route.duration_mins, selected_service.price);
    
    // Create the quote
    quote new_quote = create_quote(customer_index, pick_up, drop_off, service_index, total_price);
    new_quote.route = route;
    
    // Store the quote
    uber.quotes[uber.quote_count] = new_quote;
    uber.customers[customer_index].quote_indexes[uber.customers[customer_index].quote_count] = uber.quote_count;
    uber.customers[customer_index].quote_count++;
    uber.quote_count++;

    // Show quote visualization and get acceptance
    if(show_quote_acceptance_popup(new_quote, selected_service)) {
        checks_quote_acceptance_and_create_booking(uber, customer_index, uber.quote_count - 1);
    } else {
        // If rejected, return to menu
        return uber.quote_count - 1;
    }
}

//displays all the bookings
void show_bookings_by_status(business uber, status status, int user_index) {

    //loop through each of the bookings and deplay each booking
    for (int i = 0; i < uber.booking_count; i++)
    {
        booking curr_booking  = uber.bookings[i];

        // only displays the bookings with the status given
        if (curr_booking.status == status)
        {
            display_booking(curr_booking, uber);
        }
        
    }
    
}

//asks the customer if the wnat to book the quote givem and create the booking
void checks_quote_acceptance_and_create_booking(business &uber, int customer_index, int new_quote_index) {
    // Acceptance already handled in the window, so just proceed:
    int driver_index = 0;
    string date = read_string("Service_date: ");

    write_line("Waiting for the driver to confirm...");

    bool driver_accepted = show_driver_confirmation_popup(uber.quotes[new_quote_index], uber.services[uber.quotes[new_quote_index].service_index]);

    if (driver_accepted) {
        booking new_booking = create_booking(new_quote_index, driver_index, customer_index, date, uber);
        write_line("Booking was confirmed by the driver!");
        display_booking(new_booking, uber);
    } else {
        write_line("Booking was rejected by the driver.");
    }
}

// Returns true if accepted, false if rejected
bool show_driver_confirmation_popup(const quote &q, const service &s) {
    window popup = open_window("Driver Confirmation", 400, 300);
    delay(200);
    bool decision_made = false;
    bool accepted = false;

    while (!window_close_requested(popup) && !decision_made) {
        process_events();
        clear_screen(COLOR_WHITE);

        draw_text("New Job Request", COLOR_BLACK, "Arial", 20, 20, 20);
        draw_text("Pickup: " + q.pick_up, COLOR_BLACK, "Arial", 16, 20, 60);
        draw_text("Dropoff: " + q.drop_off, COLOR_BLACK, "Arial", 16, 20, 90);
        draw_text("Service: " + s.name, COLOR_BLACK, "Arial", 16, 20, 120);
        draw_text("Price: $" + to_string(q.total_price), COLOR_BLACK, "Arial", 16, 20, 150);

        // Accept button
        fill_rectangle(COLOR_GREEN, 50, 200, 100, 40);
        draw_text("Accept", COLOR_WHITE, "Arial", 16, 70, 210);

        // Reject button
        fill_rectangle(COLOR_RED, 250, 200, 100, 40);
        draw_text("Reject", COLOR_WHITE, "Arial", 16, 270, 210);

        if (mouse_clicked(LEFT_BUTTON)) {
            point_2d mouse = mouse_position();
            if (mouse.x >= 50 && mouse.x <= 150 && mouse.y >= 200 && mouse.y <= 240) {
                accepted = true;
                decision_made = true;
            }
            if (mouse.x >= 250 && mouse.x <= 350 && mouse.y >= 200 && mouse.y <= 240) {
                accepted = false;
                decision_made = true;
            }
        }

        refresh_screen(60);
    }

    close_window(popup);
    // Give the OS time to close the window and process events
    delay(200); // 200 ms delay
    process_events();

    return accepted;
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

//marks the booking status as completed
void mark_booking_as_completed(business &uber, int booking_index) {
    uber.bookings[booking_index].status = completed;
}

// Customer logic manager 
void customer_logic_manager(string options[], int options_length,  business &uber, int customer_index) {
    int option;

    //Greets the customer with a line
    new_text_formatted("Welcome back!");

    //Redirects to the correct function based on the user selection
    do
    {   
        //intialises quote
        int new_quote_index;

        //shows the initial menu
        display_menu(options, options_length);
        
        //Asks the customer what they want to do
        option = read_integer("Select 1 to " + to_string(options_length) + ":", 1, options_length);
        //Redirects to the correct interface based on the user selection
        switch (option)
        {
        //Creates a quote to the user
        case 1:
        case 2:
            // ask the user all the questions, calculate, create, display and return the quote
            new_quote_index = quote_form(uber, customer_index);
            break;
        case 3:
            //Show all the bookings
            show_bookings_by_status(uber, accepted, customer_index);
            break;
        case 4:
            //exits and displays a message to the user
            end_text_formatted("Bye Bye");
            break;
        default:
            end_text_formatted("Not a valid entry. Please enter a number from 1 to 4.");
            break;
        }
    } while (option !=4);
}

// Driver logic manager    
void driver_logic_manager(string options[], int options_length,  business &uber, int driver_index) {
    int option;
    int booking_index_to_mark_as_completed;
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
            //show the bookings of the driver that are accepted
            show_bookings_by_status(uber, accepted, driver_index);
            break;
        case 2:
            //show the bookings of the driver that are accepted
            show_bookings_by_status(uber, accepted, driver_index);
            
            //ask the user wich booking to mark as completed
            booking_index_to_mark_as_completed = read_integer("Select 1 to " + to_string( uber.drivers[driver_index].booking_count) + ":", 1, uber.drivers[driver_index].booking_count);

            //mark the booking as completed
            mark_booking_as_completed(uber, booking_index_to_mark_as_completed - 1);

            break;
        case 3:
            //exits and displays a message to the user
            end_text_formatted("Bye Bye");
            break;
        default:
            end_text_formatted("Not a valid entry. Please enter a number from 1 to 3.");
            break;
        }
    } while (option !=3);
}

int main() {
    // Initialize business with test data
    business uber = create_dummy_data();
    
    // Main application loop
    while(true) {
        // Display main menu
        string options[] = {"Customer", "Driver", "Exit"};
        display_menu(options, 3);
        int option = read_integer("Select an option: ", 1, 3);
        
        // Handle menu selection
        if(option == 3) break;
        
        if(option == 1) {
            // Handle customer interface
            int customer_index = 0;
            string customer_options[] = {"Request Quote", "Make a Booking", "View Bookings", "Back"};
            customer_logic_manager(customer_options, 4, uber, customer_index);
        } else if(option == 2) {
            // Handle driver interface
            int driver_index = 0;
            string driver_options[] = {"View Jobs", "Complete Job", "Back"};
            driver_logic_manager(driver_options, 3, uber, driver_index);
        }
    }
    
    return 0;
}
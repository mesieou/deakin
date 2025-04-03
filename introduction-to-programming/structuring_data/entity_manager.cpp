#include "splashkit.h"
#include <sstream>
#include <cstdlib> 

using std::to_string;
using namespace std;

//define the struct book_data to store the book details 
struct book_data 
{
    string name;
    string location;
    int pages;
};

//define a Enum with the menu options
enum menu_options
{
    READ,
    PRINT,
    QUIT
};
// read and return a user string input
string read_string(string prompt)
{
    write_line(prompt);
    return read_line();
}

// read and return a user number input and checks it is a number
int read_integer(string prompt, 
    int from = numeric_limits<int>::min(), 
    int to = numeric_limits<int>::max())
{
    string user_output = read_string(prompt);
    
    while(!is_integer(user_output))
    {
        write_line("Please enter a whole number");
        user_output = read_string(prompt);
    }

    int user_output_int = convert_to_integer(user_output);
    while (!(user_output_int > from and user_output_int < to))
    {
        stringstream ss;
        ss << "Please enter a number from " << from << " to " << to;

        write_line( ss.str());
        user_output_int = convert_to_integer(read_string(prompt));
    }
    return user_output_int;
}

//represent the menu option as string
string option_to_string(menu_options option)
{
    switch (option)
    {
    case READ:
        /* code */
        return "Read book";    
    case PRINT:
        /* code */
        return "Print book";
    case QUIT:
    /* code */
    return "Quit";
    default:
        return "Unknown";
    }
}

//show the menu and read the user input
menu_options read_menu(string question)
{
    write_line("");
    //loops through the menu and displays the menu
    for (int i = 0; i < QUIT + 1; i++)
    {
        write_line(to_string(i + 1 ) + " - " + option_to_string(menu_options(i)));
    }

    //stores the number chosen by the user
    int option = read_integer("Option: ") - 1;
    
    //converts the number chosen into a enum value and returns it
    return (menu_options) option;
}

//create a new book and it returns it
book_data new_book(string name, string location, int pages)
{
    book_data book = { name, location, pages };
    return book;
}
//define the menu enum

//show menu and return a book
book_data read_book()
{
    write_line("Book Entry System.\n");
    string book_name = read_string("Enter the name of the book: ");
    string book_location = read_string("Enter book location: ");
    int book_pages = read_integer("Enter number of pages: ");

    book_data book = new_book(book_name, book_location, book_pages);
    
    return book;
}

//output the book details
void output_book_details(book_data book)
{
    write_line("");
    write_line("Title: " + book.name);
    write_line("Location: " + book.location);
    write_line("Pages: "+ to_string(book.pages) + "\n");
}

//initial method as soon the program is run
int main()
{
    //ask user for the book details and store it in the book struct
    book_data book = read_book();
    
    //initialise the option value inside the enum
    menu_options option_selected;
    
    //stays in a loop until the user exits
    do
    {   
        //show the menu to the user and save the option
        option_selected = read_menu("Menu: ");

        //do different actions depending on the option selected by the user
        switch (option_selected)
        {
        case READ:
            //open the website given as representestion of a book
            system("open https://programmers.guide");
            break;
        case PRINT:
            //show the user the book details
            output_book_details(book);
            break;
        default:
            break;
        }
    } while (option_selected != 2);
    
}
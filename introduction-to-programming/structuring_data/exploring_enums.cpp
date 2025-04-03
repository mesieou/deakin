#include "splashkit.h"
#include "../utilities/utilities.h"

using std::to_string;

// add enumeration here called 'day'
enum day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

string to_string(day d)
{
    switch (d)
    {
    case MONDAY:
        /* code */
        return "Monday";
        break;
    case TUESDAY:
        /* code */
        return "Tuesday";
        break;
    case WEDNESDAY:
        /* code */
        return "Wednesday";
        break;
    case THURSDAY:
        /* code */
        return "Thursday";
        break;
    case FRIDAY:
        /* code */
        return "Friday";
        break;
    case SATURDAY:
        /* code */
        return "Saturday";
        break;
    case SUNDAY:
        /* code */
        return "Sunday";
        break;
    
    default:
        return "Unknown";    
    }
}

const int NUMBER_OF_DAYS = SUNDAY + 1;

day read_day(string question)
{
    for ( int i = 0; i < NUMBER_OF_DAYS; i++ )
    {
        write_line(to_string(i + 1) + ": "  + to_string(day(i)));
    }
    int option = read_integer(question) - 1;
    return (day) option;

}

int main()
{
    // Enum variable declaration
    day today;

    // Assigning a value to the enum variable
    today = read_day("Enter a day: ");

    // Print the value of today
    write_line("Today is day number " + to_string(today));

    return 0;
}
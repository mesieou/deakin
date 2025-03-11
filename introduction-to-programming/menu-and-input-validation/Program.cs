using static System.Convert;
using static SplashKitSDK.SplashKit;

int choice;
string line;

do
{
    WriteLine("1: Addition");
    WriteLine("2: Substraction");
    WriteLine("3: Multiplication");
    WriteLine("4: Divition");
    WriteLine("5: Quit");
    WriteLine("Enter your Choice: ");
    line = ReadLine();

    while (! IsInteger(line) ){
        WriteLine("Invalid format. Please type a number like 4");
        WriteLine("Enter your Choice: ");
        line = ReadLine();

    }
    choice = ToInt32(line);

    switch(choice)
    {
        case 1: 
        WriteLine("Addition");
        break;
        case 2:
        WriteLine("Substraction");
        break;
        case 3:
        WriteLine("Multiplication");
        break;
        case 4:
        WriteLine("Divition");
        break;
        case 5:
        WriteLine("Quit");
        break;
        default:
        WriteLine("Incorrect input!. Please enter a number from the menu:");
        break;
    }
} while(choice != 5);

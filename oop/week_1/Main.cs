class Main
{
    Console.WriteLine("Enter a number");
input
    try
    {
        int number = Convert.ToInt32(input);

        switch (number)
        {
            case 1: Console.WriteLine("One");
            case 2: Console.WriteLine("Two");
            case 3: Console.WriteLine("T");
            case 4: Console.WriteLine("One");
            case 5: Console.WriteLine("One");
            case 6: Console.WriteLine("One");
            case 7: Console.WriteLine("One");
            case 8: Console.WriteLine("One");
            case 9: Console.WriteLine("One");
            default: Console.WriteLine("Number must be between 0 and 9.");
        }
    }
    catch (FormatException)
    {
        Console.WriteLine("That wasn’t a valid integer.");
    }


}
// See https://aka.ms/new-console-template for more information

class DivisibleFour
{
    static void Main(string[] args)
    {
        int number = 0;

        //ask the user
        Console.WriteLine("Please type a number: ");
        try
        {
            //get the user input
            number = Convert.ToInt32(Console.ReadLine());
        }
        catch (FormatException)
        {
            Console.WriteLine("That is not a valid integer");
        }

        for (int i = 0; i < number; i++)
        {
            if (i % 4 == 0)
            {
                //if the number is divisible by four then print it to the user
                Console.WriteLine($"{i} is divisible by four");
                
            }
        }
    }
}
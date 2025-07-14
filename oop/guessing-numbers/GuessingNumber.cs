// See https://aka.ms/new-console-template for more information
class GuessingNumber
{
    static void Main(string[] args)
    {
        int number = 5;
        int input = 0;
        do
        {
            try
            {
                Console.WriteLine("Guess a number between 1 and 10: ");
                input = Convert.ToInt32(Console.ReadLine());
                if (input == number)
                {
                    Console.WriteLine("Congrats!, you have guessed the number!.");
                }
                else if (input > 10)
                {
                    Console.WriteLine("You have entered a number greater than 10.");
                }
                else if (input < 1)
                {
                    Console.WriteLine("You have entered a number less than 1");
                }

            }
            catch (FormatException)
            {
                Console.WriteLine("That is not a valid integer.");
            }


        } while (input != number);
    }
}
// See https://aka.ms/new-console-template for more information
class GuessingNumber
{
    //helper function to get a valid integer
    static int GetInt(string prompt)
    {
        int input = 0;
        bool inputIsValid = false;

        do
        {
            try
            {
                Console.WriteLine(prompt);
                input = Convert.ToInt32(Console.ReadLine());
                if (input > 10)
                {
                    Console.WriteLine("You have entered a number greater than 10.");
                }
                else if (input < 1)
                {
                    Console.WriteLine("You have entered a number less than 1");
                }
                else
                {
                    inputIsValid = true;
                }
            }
            catch (FormatException)
            {
                Console.WriteLine("That is not a valid integer.");
                inputIsValid = false;
            }

        } while (!inputIsValid);

        return input;
    }



    static void Main(string[] args)
    {
        //Takes the user 1 input and checks is valid.
        int inputUser1 = GetInt("User 1, type a number between 1 and 10 for user 2 to guess: ");

        //Takes the user 2 input and checks is valid.
        int inputUser2 = GetInt("User 2, type a number between 1 and 10: ");

        //Checks user 1 input against user 2 input until guessed.
        do
        {
            if (inputUser1 == inputUser2)
            {
                Console.WriteLine("Congrats!, you have guessed the number!.");
            }
            else
            {
                Console.WriteLine("Keep trying");
            }
        } while (inputUser1 != inputUser2);
    }
}
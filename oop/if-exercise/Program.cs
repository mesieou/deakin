namespace Week1App;          // optional but recommended

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Enter a number (0‑9): ");
        string input = Console.ReadLine();

        try
        {
            int number = Convert.ToInt32(input);

            if (number < 1 || number > 9)
                throw new Exception("Number must be between 0 and 9.");

            else if (number == 1) Console.WriteLine("ONE");
            else if (number == 2) Console.WriteLine("TWO");
            else if (number == 3) Console.WriteLine("THREE");
            else if (number == 4) Console.WriteLine("FOUR");
            else if (number == 5) Console.WriteLine("FIVE");
            else if (number == 6) Console.WriteLine("SIX");
            else if (number == 7) Console.WriteLine("SEVEN");
            else if (number == 8) Console.WriteLine("EIGHT");
            else /* number == 9 */Console.WriteLine("NINE");
        }
        catch (FormatException)
        {
            Console.WriteLine("That wasn’t a valid integer.");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"{ex.Message}");
        }
    }
}

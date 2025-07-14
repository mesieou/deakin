using System.Threading.Tasks.Dataflow;

class Microwave
{
    static void Main(string[] args)
    {
        Console.WriteLine("Enter the heating Time in seconds: ");
        int heatingTimeInSeconds = 0;

        try
        {
            heatingTimeInSeconds = Convert.ToInt32(Console.ReadLine());
        }
        catch (FormatException)
        {
            Console.WriteLine("That was not a valid integer");
            return;
        }


        Console.WriteLine("Enter the number of Items from 1 to 4: ");
        try
        {
            int number = Convert.ToInt32(Console.ReadLine());

            if (number < 1)
            {
                throw new Exception("Please enter an number greater than 0.");
            }
            else if (number == 2)
            {
                heatingTimeInSeconds = (int)(heatingTimeInSeconds * 1.5);
            }
            else if (number == 3)
            {
                heatingTimeInSeconds = heatingTimeInSeconds * 2;
            }
            else
            {
                Console.WriteLine("Heating with more than 3 items it is not recommended");
            }

            Console.WriteLine($"Heat for {heatingTimeInSeconds} seconds");

        }
        catch (FormatException)
        {
            Console.WriteLine("That was not a valid integer");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"{ex.Message}");
        }
    }
}

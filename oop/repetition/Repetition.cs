// See https://aka.ms/new-console-template for more information
using System.Globalization;
using System.Threading.Tasks.Dataflow;

class Repetition
{
    static void Main(string[] args)
    {
        int sumForLoop = 0;
        double avergageForLoop;
        int upperbound = 100;

        for (int num = 1; num <= upperbound; num++)
        {
            sumForLoop += num;
        }
        avergageForLoop = (double)sumForLoop / upperbound;

        int number = 1;
        int sumWhileLoop = 0;
        double avergageWhileLoop;


        while (number <= upperbound)
        {
            sumWhileLoop += number;
            number++;
        }
        avergageWhileLoop = (double)sumWhileLoop / upperbound;

        int n = 1;
        int sumDoWhileLoop = 0;
        double avergageDoWhileLoop;


        do
        {
            sumDoWhileLoop += n;
            n++;
        } while (n <= upperbound);

        avergageDoWhileLoop = (double)sumDoWhileLoop / upperbound;


        Console.WriteLine(sumForLoop);
        Console.WriteLine(avergageForLoop);

        Console.WriteLine(sumForLoop);
        Console.WriteLine(avergageWhileLoop);

        Console.WriteLine(sumDoWhileLoop);
        Console.WriteLine(avergageDoWhileLoop);
    }
}

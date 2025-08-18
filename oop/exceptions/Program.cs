// See https://aka.ms/new-console-template for more information
using System.Runtime.CompilerServices;

class Account
{
    public string FirstName { get; private set; }
    public string LastName { get; private set; }
    public int Balance { get; private set; }

    public Account(string firstName, string lastName, int balance)
    {
        FirstName = firstName;
        LastName = lastName;
        Balance = balance;
    }

    public void Withdraw(int amount)
    {
        if (amount > Balance)
        {
            //InvalidOperationException
            throw new InvalidOperationException("Insufficient fund");
        }
        Balance -= amount;
    }
}

class Program
{
    static void Main()
    {
        // //NullReferenceException
        // Account myAccount = null;

        // try
        // {
        //     myAccount.Withdraw(50);
        // }
        // catch (NullReferenceException ex)
        // {
        //     Console.WriteLine("NullReferenceException found: " + ex.Message);
        // }

        // //IndexOutOfRangeException
        // int[] array = new int[100];
        // try
        // {
        //     array[101] = 33;

        // }
        // catch (IndexOutOfRangeException ex)
        // {

        //     Console.WriteLine("IndexOutOfRangeException found: " + ex.Message);
        // }


        // //StackOverflowException
        // static void RecursiveMethod()
        // {
        //     // This method keeps calling itself with no stop condition
        //     RecursiveMethod();
        // }

        // try
        // {
        //     RecursiveMethod();
        // }
        // catch (StackOverflowException ex)
        // {

        //     Console.WriteLine("StackOverflowException found: " + ex.Message);
        // }


        // //OutOfMemoryException
        // try
        // {
        //     List<byte[]> allocations = new List<byte[]>();

        //     while (true)
        //     {
        //         // Allocate 100 MB chunks repeatedly
        //         allocations.Add(new byte[100_000_000]);
        //     }
        // }
        // catch (OutOfMemoryException ex)
        // {
        //     Console.WriteLine("OutOfMemoryException found: " + ex.Message);
        // }

        //DivideByZeroException
        // try
        // {
        //     int a = 10;
        //     int b = 0;
        //     int result = a / b;
        // }
        // catch (DivideByZeroException ex)
        // {
        //     Console.WriteLine("DivideByZeroException found: " + ex.Message);

        // }

        //ArgumentNullException
        // string text = null;
        // Console.WriteLine(text.Length);

        //ArgumentOutOfRangeException
        // string text = "hello";
        // string sub = text.Substring(10);

        //FormatException
        // try
        // {
        //     int num = int.Parse("abc");
        // }
        // catch (FormatException ex)
        // {
        //     Console.WriteLine("FormatException found: " + ex.Message);
        // }

        //ArgumentException
        // static void SetUsername(string username)
        // {
        //     if (username.Length < 3)
        //         throw new ArgumentException("Username must be at least 3 characters long.", nameof(username));
        // }

        // try
        // {
        //     SetUsername("Jo");
        // }
        // catch (ArgumentException ex)
        // {
        //     Console.WriteLine("ArgumentException found: " + ex.Message);
        // }

        //SystemException
        try
        {
            int[] arr = new int[3];
            Console.WriteLine(arr[10]); // IndexOutOfRangeException
        }
        catch (SystemException ex)
        {
            Console.WriteLine($"Caught a system exception: {ex.GetType().Name} - {ex.Message}");
        }


    }
}





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
        //NullReferenceException
        Account myAccount = null;

        try
        {
            myAccount.Withdraw(50);
        }
        catch (NullReferenceException ex)
        {
            Console.WriteLine("NullReferenceException found: " + ex.Message);
        }

        //index out of reference
        int[] array = new int[100];
        try
        {
            array[101] = 33;

        }
        catch (IndexOutOfRangeException ex)
        {

            Console.WriteLine("IndexOutOfRangeException found: " + ex.Message);
        }

        //OutOfMemoryException
        string value = new string('a', int.MaxValue);
    }


}



class StackOverflowException
{

}

class OutOfMemoryException
{

}

class DivideByZeroException
{

}

class ArgumentNullException
{

}

class ArgumentOutOfRangeException
{

}

class FormatException
{

}

class ArgumentException
{

}

class SystemException
{

}






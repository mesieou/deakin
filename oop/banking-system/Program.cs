// See https://aka.ms/new-console-template for more information
class Account
{
    private string name;
    private double balance;

    public Account(string name, double balance)
    {
        this.name = name;
        this.balance = balance;
    }

    public void Deposit(double amount)
    {
        this.balance += amount;
    }

    public void Withdraw(double amount)
    {

        if (this.balance - amount > 0)
        {
            this.balance -= amount;
        }
        else
        {
            Console.WriteLine($"Sorry, not enough balance to withdraw {amount}");
            Console.WriteLine($"Your current balance is {this.balance}");
            Console.WriteLine();
        }
    }

    public void Print()
    {
        Console.WriteLine($"Account Name: {this.name}");
        Console.WriteLine($"Account Balance: {this.balance}");
        Console.WriteLine();
    }

    public string Name()
    {
        return this.name;
    }
}

class TestAccount()
{
    static void Main()
    {
        //test account initialisation
        Account savings = new Account("Savings", 350);
        savings.Print();

        //test deposit
        savings.Deposit(54);
        savings.Print();

        //test withdrawal
        savings.Withdraw(30);
        savings.Print();

        //test to withdraw more than the current balance
        savings.Withdraw(380);
        savings.Print();

        //test getting the name
        string savingsName = savings.Name();
        Console.WriteLine(savingsName);
    }
}
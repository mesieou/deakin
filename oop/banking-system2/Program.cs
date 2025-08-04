class Account
{
    private string name;
    private double balance;

    public Account(string name, double balance)
    {
        this.name = name;
        this.balance = balance;
    }

    public bool Deposit(double amount)
    {
        if (amount > 0)
        {
            this.balance += amount;
            return true;
        } else
        {
            return false;
        }
    }

    public bool Withdraw(double amount)
    {

        if (this.balance - amount > 0)
        {
            this.balance -= amount;
            return true;
        }
        else
        {
            Console.WriteLine($"Sorry, not enough balance to withdraw {amount}");
            Console.WriteLine($"Your current balance is {this.balance}");
            Console.WriteLine();
            return false;
        }
    }

    class BankSystem()
    {

    }
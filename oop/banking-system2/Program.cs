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
        }
        else
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

}
enum MenuOption { Withdraw = 1, Deposit, Print, Quit }
class BankSystem()
{
    static int ReadUserOption()
    {
        int option = 0;
        int enumSize = Enum.GetValues(typeof(MenuOption)).Length;

        do
        {
            Console.WriteLine($"Please type a number a number from the menu: ");
            foreach (MenuOption choice in Enum.GetValues(typeof(MenuOption)))
            {
                Console.WriteLine($"{(int)choice}. {choice}");
            }
            option = Convert.ToInt32(Console.ReadLine());

        } while (option < 1 || option > enumSize);
        return option;
    }

    static void Main()
    {
        int choice = ReadUserOption();
        Console.WriteLine(choice);

    }
}
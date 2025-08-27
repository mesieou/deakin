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
enum MenuOption { Withdraw = 1, Deposit, Print, Quit }
class BankSystem()
{
  static int ReadUserOption()
  {
    int option = 0;
    int enumSize = Enum.GetValues(typeof(MenuOption)).Length;

    do
    {
      string menuMessage = "Please type a number from the menu:\n";
      foreach (MenuOption choice in Enum.GetValues(typeof(MenuOption)))
      {
        menuMessage += $"{(int)choice}. {choice}\n";
      }
      option = ReadInteger(menuMessage);


    } while (option < 1 || option > enumSize);
    return option;
  }

  static string ReadString(string message = "")
  {
    string reply;
    int number;
    do
    {
      Console.WriteLine(message);
      reply = Console.ReadLine();

    } while (int.TryParse(reply, out number));
    return reply;
  }

  static int ReadInteger(string message = "")
  {
    string reply;
    int number;
    do
    {
      if (!string.IsNullOrEmpty(message))
        Console.WriteLine(message);

      reply = Console.ReadLine();

    } while (!int.TryParse(reply, out number));

    return number;
  }

  static void Main()
  {
    int choice = 0;
    //test account initialisation
    Account savings = new Account("Savings", 350);
    string userIsSure = "";

    do
    {
      choice = ReadUserOption();
      switch (choice)
      {
        case 1:
          DoWithdraw(savings);
          DoPrint(savings);
          break;
        case 2:
          DoDeposit(savings);
          DoPrint(savings);
          break;
        case 3:
          DoPrint(savings);
          break;
        default:
          Console.WriteLine("Invalid choice.");
          break;
      }
    } while (choice != 4);

    bool IsSure(string userReply)
    {
      while (userReply.ToLower() != "y" && userReply.ToLower() != "n")
      {
        Console.WriteLine("please type y or n only");
      }
      if (userReply.ToLower() == "y")
      {
        return true;
      }
      else
      {
        return false;
      }
    }



    void DoDeposit(Account account)
    {
      int amount = ReadInteger("How much would you like to deposit?:");

      string ans = ReadString($"Are you sure you want to {MenuOption.Deposit} {amount}? Y/N");
      if (IsSure(ans))
      {
        account.Deposit(amount);
      }
    }

    void DoWithdraw(Account account)
    {
      int amount = ReadInteger("How much would you like to withdraw?:");

      string ans = ReadString($"Are you sure you want to {MenuOption.Withdraw} {amount}? Y/N");
      if (IsSure(ans))
      {
        WithdrawTransaction transaction = new WithdrawTransaction(account, amount);
        transaction.Execute();
        transaction.Print();
      }
    }

    void DoPrint(Account account)
    {
      account.Print();
    }

  }
}

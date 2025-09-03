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
enum MenuOption { Withdraw = 1, Deposit, Transfer, Print, AddAccount, Quit }
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

  static Account FindAccount(Bank bank)
  {
    string accountName = ReadString("Enter account name:");
    Account account = bank.GetAccount(accountName);
    if (account == null)
    {
      Console.WriteLine($"Account '{accountName}' not found.");
    }
    return account;
  }

  static void Main()
  {
    int choice = 0;
    Bank bank = new Bank();
    // Initialize with test accounts
    Account savings = new Account("Savings", 350);
    Account transactional = new Account("Transactional", 100);
    bank.AddAccount(savings);
    bank.AddAccount(transactional);
    string userIsSure = "";

    do
    {
      choice = ReadUserOption();
      switch (choice)
      {
        case 1:
          DoWithdraw(bank);
          break;
        case 2:
          DoDeposit(bank);
          break;
        case 3:
          DoTransfer(bank);
          break;
        case 4:
          DoPrint(bank);
          break;
        case 5:
          DoAddAccount(bank);
          break;
        default:
          Console.WriteLine("Invalid choice.");
          break;
      }
    } while (choice != 6);

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



    void DoAddAccount(Bank bank)
    {
      string accountName = ReadString("Enter account name:");
      int startingBalance = ReadInteger("Enter starting balance:");

      Account newAccount = new Account(accountName, startingBalance);
      bank.AddAccount(newAccount);

      Console.WriteLine($"Account '{accountName}' created successfully with balance ${startingBalance}");
      Console.WriteLine();
    }

    void DoDeposit(Bank bank)
    {
      Account account = FindAccount(bank);
      if (account == null)
      {
        return;
      }

      int amount = ReadInteger("How much would you like to deposit?:");

      string ans = ReadString($"Are you sure you want to {MenuOption.Deposit} {amount}? Y/N");
      if (IsSure(ans))
      {
        DepositTransaction transaction = new DepositTransaction(account, amount);
        bank.ExecuteTransaction(transaction);
        transaction.Print();
        account.Print();
      }
    }

    void DoWithdraw(Bank bank)
    {
      Account account = FindAccount(bank);
      if (account == null)
      {
        return;
      }

      int amount = ReadInteger("How much would you like to withdraw?:");

      string ans = ReadString($"Are you sure you want to {MenuOption.Withdraw} {amount}? Y/N");
      if (IsSure(ans))
      {
        WithdrawTransaction transaction = new WithdrawTransaction(account, amount);
        bank.ExecuteTransaction(transaction);
        transaction.Print();
        account.Print();
      }
    }

    void DoTransfer(Bank bank)
    {
      Console.WriteLine("Select the account to transfer FROM:");
      Account fromAccount = FindAccount(bank);
      if (fromAccount == null)
      {
        return;
      }

      Console.WriteLine("Select the account to transfer TO:");
      Account toAccount = FindAccount(bank);
      if (toAccount == null)
      {
        return;
      }

      int amount = ReadInteger("How much would you like to transfer?:");

      string ans = ReadString($"Are you sure you want to transfer {amount} from {fromAccount.Name()} to {toAccount.Name()}? Y/N");
      if (IsSure(ans))
      {
        TransferTransaction transaction = new TransferTransaction(fromAccount, toAccount, amount);
        bank.ExecuteTransaction(transaction);
        transaction.Print();
        fromAccount.Print();
        toAccount.Print();
      }
    }

    void DoPrint(Bank bank)
    {
      Account account = FindAccount(bank);
      if (account == null)
      {
        return;
      }
      account.Print();
    }

  }
}

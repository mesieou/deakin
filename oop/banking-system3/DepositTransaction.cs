class DepositTransaction
{
  private Account _account;
  private double _amount;
  private bool _executed;
  private bool _success;
  private bool _reversed;

  public DepositTransaction(Account account, double amount)
  {
    _account = account;
    _amount = amount;
    _executed = false;
    _success = false;
    _reversed = false;
  }

  public void Execute()
  {
    if (_executed)
    {
      throw new InvalidOperationException("Transaction already executed");
    }
    _executed = true;

    // directly call Account.Deposit()
    _success = _account.Deposit(_amount);
  }

  public void Print()
  {
    Console.WriteLine($"Deposit {_amount} from {_account.Name()} was " +
      $"{(_success ? "successful" : "unsuccessful")}");
  }
  public void Rollback()
  {
    if (!_executed)
    {
      throw new InvalidOperationException("Transaction not executed");
    }
    if (_reversed)
    {
      throw new InvalidOperationException("Transaction already reversed");
    }
    if (_success)
    {
      _account.Withdraw(_amount);
      _reversed = true;
    }
  }
}

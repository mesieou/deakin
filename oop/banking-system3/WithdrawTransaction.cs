class WithdrawTransaction
{
  private Account _account;
  private double _amount;   // make it double to match Account
  private bool _executed;
  private bool _success;
  private bool _reversed;

  public WithdrawTransaction(Account account, double amount)
  {
    _account = account;
    _amount = amount;
    _executed = false;
    _success = false;
    _reversed = false;
  }

  public void Print()
  {
    Console.WriteLine($"Withdraw {_amount} from {_account.Name()} was " +
      $"{(_success ? "successful" : "unsuccessful")}");
  }

  public void Execute()
  {
    if (_executed)
    {
      throw new InvalidOperationException("Transaction already executed");
    }
    _executed = true;

    // directly call Account.Withdraw()
    _success = _account.Withdraw(_amount);
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
      _account.Deposit(_amount);
      _reversed = true;
    }
  }
}

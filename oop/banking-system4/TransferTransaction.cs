class TransferTransaction
{
  private Account _fromAccount;
  private Account _toAccount;
  private double _amount;
  private DepositTransaction _depositTransaction;
  private WithdrawTransaction _withdrawTransaction;
  private bool _executed;
  private bool _reversed;

  public TransferTransaction(Account fromAccount, Account toAccount, double amount)
  {
    _fromAccount = fromAccount;
    _toAccount = toAccount;
    _amount = amount;
    _depositTransaction = new DepositTransaction(_toAccount, _amount);
    _withdrawTransaction = new WithdrawTransaction(_fromAccount, _amount);
    _executed = false;
    _reversed = false;
  }

  public void Execute()
  {
    if (_executed)
    {
      throw new InvalidOperationException("Transaction already executed");
    }
    _executed = true;

    // execute withdraw first
    _withdrawTransaction.Execute();
    // if withdraw successful, execute deposit
    if (_withdrawTransaction != null)
    {
      _depositTransaction.Execute();
      // if deposit failed, rollback withdraw
      if (_depositTransaction == null)
      {
        _withdrawTransaction.Rollback();
        throw new InvalidOperationException($"Deposit transaction failed, to {_toAccount.Name()}.");
      }
    }
    else
    {
      // withdraw failed
      throw new InvalidOperationException($"Withdraw transaction failed, from {_fromAccount.Name()} has insufficient funds.");
    }
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
    // rollback deposit first
    _depositTransaction.Rollback();
    // then rollback withdraw
    _withdrawTransaction.Rollback();
    _reversed = true;
  }
  public void Print()
  {
    Console.WriteLine($"Transfer {_amount} from {_fromAccount.Name()} to {_toAccount.Name()} was " +
      $"{(_withdrawTransaction != null && _depositTransaction != null ? "successful" : "unsuccessful")}");
  }
}

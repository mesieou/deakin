// See https://aka.ms/new-console-template for more information
using System.Net.NetworkInformation;

class Mobile
{
    private String accType, device, number;
    private double balance;

    //VARIABLES
    private const double CALL_COST = 0.245;
    private const double TEXT_COST = 0.078;

    public Mobile(String accType, String device, String number)
    {
        this.accType = accType;
        this.device = device;
        this.number = number;
        this.balance = 0.0;
    }

    public String getAccType()
    {
        return this.accType;
    }
    public String getDevice()
    {
        return this.device;
    }
    public String getNumber()
    {
        return this.number;
    }
    public String getBalance()
    {
        return this.balance.ToString("C");
    }
    public void setAccType(String accType)
    {
        this.accType = accType;
    }
    public void setDevice(String device)
    {
        this.device = device;
    }
    public void setNumber(String number)
    {
        this.number = number;
    }
    public void setBalance(double balance)
    {
        this.balance = balance;
    }

    //Methods
    public void addCredit(double amount)
    {
        this.balance += amount;
        Console.WriteLine("Credit added succesfully. New balance " + getBalance());
    }
    public void makeCall(int minutes)
    {
        double cost = minutes * CALL_COST;
        this.balance -= cost;
        Console.WriteLine("Called made. New balance " + getBalance());
    }
    public void sendText(int numTexts)
    {
        double cost = numTexts * TEXT_COST;
        this.balance -= cost;
        Console.WriteLine("Text sent. New balance " + getBalance());
    }

}
class MobileProgram
{
    static void Main()
    {
        Mobile jimMobile = new Mobile("Monthly", "Samsung Galaxy S6", "07712223344");

        Console.WriteLine("Account Type: " + jimMobile.getAccType() +
                          "\nMobile Number: " + jimMobile.getNumber() +
                          "\nDevice: " + jimMobile.getDevice() +
                          "\nBalance: " + jimMobile.getBalance());
        Console.ReadLine();


        jimMobile.setAccType("PAYG");
        jimMobile.setDevice("iPhone 6S");
        jimMobile.setNumber("07713334466");
        jimMobile.setBalance(15.50);

        Console.WriteLine();
        Console.WriteLine("Account Type: " + jimMobile.getAccType() +
                          "\nMobile Number: " + jimMobile.getNumber() +
                          "\nDevice: " + jimMobile.getDevice() +
                          "\nBalance: " + jimMobile.getBalance());
        Console.ReadLine();

        Console.WriteLine();
        jimMobile.addCredit(10.0);
        jimMobile.makeCall(5);
        jimMobile.sendText(2);

        Console.ReadLine();

        //create new mobile, add some credit, make some call and send some texts
        Mobile juanMobile = new Mobile("PAYG", "iPhone 11", "0473164581");
        juanMobile.addCredit(50.0);
        juanMobile.makeCall(7);
        juanMobile.sendText(8);

    }
}

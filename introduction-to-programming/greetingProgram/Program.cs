using static System.Console;

new Greeting("Welcome to C# programming!").Print();

class Greeting
{
    private string _message;  // field to store the message

    public Greeting(string message)
    {
        _message = message;
    }

    public void Print()
    {
        WriteLine(_message);
    }

    public void Greet(string name)
    {
        WriteLine($"Hello {name}! {_message}");
    }

    public string Message
    {
        get { return _message; }
        set { _message = value; }
    }
}

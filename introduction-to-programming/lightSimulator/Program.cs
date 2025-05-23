using System;

class Light
{
    // Instance variables (fields)
    private bool _isOn;
    private string _color;
    private int _brightness;
    private string _location;

    // Constructor
    public Light(string location, string color = "White", int brightness = 100)
    {
        _location = location;
        _color = color;
        _brightness = brightness;
        _isOn = false;
    }

    // Properties
    public bool IsOn
    {
        get { return _isOn; }
    }

    public string Color
    {
        get { return _color; }
        set { _color = value; }
    }

    public int Brightness
    {
        get { return _brightness; }
        set 
        { 
            if (value >= 0 && value <= 100)
                _brightness = value;
            else
                Console.WriteLine("Brightness must be between 0 and 100");
        }
    }

    // Methods
    public void TurnOn()
    {
        _isOn = true;
        Console.WriteLine($"Light in {_location} is now ON");
    }

    public void TurnOff()
    {
        _isOn = false;
        Console.WriteLine($"Light in {_location} is now OFF");
    }

    public void ChangeColor(string newColor)
    {
        _color = newColor;
        Console.WriteLine($"Light color changed to {_color}");
    }

    public void Dim(int amount)
    {
        if (_brightness - amount >= 0)
        {
            _brightness -= amount;
            Console.WriteLine($"Light dimmed to {_brightness}%");
        }
        else
        {
            Console.WriteLine("Cannot dim below 0%");
        }
    }

    public void Brighten(int amount)
    {
        if (_brightness + amount <= 100)
        {
            _brightness += amount;
            Console.WriteLine($"Light brightened to {_brightness}%");
        }
        else
        {
            Console.WriteLine("Cannot brighten above 100%");
        }
    }

    public void DisplayStatus()
    {
        Console.WriteLine($"\nLight Status:");
        Console.WriteLine($"Location: {_location}");
        Console.WriteLine($"State: {(_isOn ? "ON" : "OFF")}");
        Console.WriteLine($"Color: {_color}");
        Console.WriteLine($"Brightness: {_brightness}%");
    }
}

// Main program to demonstrate the Light class
class Program
{
    static void Main(string[] args)
    {
        // Create a new light instance
        Light livingRoomLight = new Light("Living Room", "Warm White", 80);
        
        // Demonstrate various methods
        Console.WriteLine("Light Simulator Demo\n");
        
        livingRoomLight.DisplayStatus();
        livingRoomLight.TurnOn();
        livingRoomLight.ChangeColor("Blue");
        livingRoomLight.Dim(20);
        livingRoomLight.DisplayStatus();
        
        livingRoomLight.Brighten(30);
        livingRoomLight.ChangeColor("Red");
        livingRoomLight.DisplayStatus();
        
        livingRoomLight.TurnOff();
        livingRoomLight.DisplayStatus();
    }
}

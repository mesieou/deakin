// See https://aka.ms/new-console-template for more information
class Car
{
    private int fuel, miles;
    private double mpg;
    private const double COST_PER_LITER = 1.385;

    public Car(double mpg)
    {
        this.mpg = mpg;
        this.fuel = 0;
        this.miles = 0;
    }

    public int getFuel()
    {
        return this.fuel;
    }

    public int getTotalMiles()
    {
        return this.miles;
    }

    public void setTotalMiles(int miles)
    {
        this.miles = miles;
    }

    public void printFuelCost()
    {
        Console.WriteLine(COST_PER_LITER.ToString("C"));
    }

    public void addFuel(int fuel)
    {
        this.fuel += fuel;
    }

    public string calcCost(int fuel)
    {
        double cost = fuel * COST_PER_LITER;
        return cost.ToString("C");
    }

    public int convertToLitres(double gallons)
    {
        int litters = Convert.ToInt32(gallons * 3.78541);
        return litters;
    }

    public void drive(int miles)
    {
        //update miles
        this.miles += miles;

        //update fuel used
        double gallonslUsed = miles / this.mpg;
        int littersUsed = convertToLitres(gallonslUsed);
        this.fuel -= littersUsed;
        Console.WriteLine("Total cost of the Journey: " + calcCost(littersUsed));
    }

    public void printStateCar()
    {
        Console.WriteLine($"Car mpg: {this.mpg}");
        Console.WriteLine($"Car miles: {this.miles}");
        Console.WriteLine($"Car fuel: {this.fuel}");
        Console.ReadLine();
    }
}

class CarProgram()
{
    static void Main()
    {
        //Test Initialising car
        Car myCar = new Car(31.25);
        myCar.printStateCar();

        //Test getting the fuel and miles
        Console.WriteLine("My car fuel is: " + myCar.getFuel());
        Console.WriteLine("My car miles are: " + myCar.getTotalMiles());
        Console.ReadLine();

        //Test setting miles
        myCar.setTotalMiles(20);
        myCar.printStateCar();

        //Test print fuel cost
        myCar.printFuelCost();
        Console.ReadLine();


        //Test add fuel
        myCar.addFuel(25);
        myCar.printStateCar();

        //Test calc Cost
        string myCarFuelCost = myCar.calcCost(myCar.getFuel());
        Console.WriteLine("Total Cost: " + myCarFuelCost);
        Console.ReadLine();


        //Test convert to litres
        int litters = myCar.convertToLitres(20);
        Console.WriteLine("Gallons: " + 20);
        Console.WriteLine("Converted to litters: " + litters);
        Console.ReadLine();

        //Test drive
        myCar.drive(20);
        myCar.printStateCar();
    }
}
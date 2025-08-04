// See https://aka.ms/new-console-template for more information
using System.Runtime.CompilerServices;

class Employee
{
    private String name;
    private double salary;

    public Employee(string employeeName, double currentSalary)
    {
        this.name = employeeName;
        this.salary = currentSalary;
    }

    public String getName()
    {
        return this.name;
    }

    public String getSalary()
    {
        return this.salary.ToString("C");
    }

    public void raiseSalary(int percentage)
    {
        this.salary += this.salary * percentage / 100;
    }

    public string tax()
    {
        double taxPayble = 0;
        double bracketAmout = 0;

        if (this.salary > 18200 && this.salary <= 37000)
        {
            bracketAmout = this.salary - 18200;
            taxPayble = bracketAmout * 0.19;
        }
        else if (this.salary > 37000 && this.salary <= 90000)
        {
            bracketAmout = this.salary - 37000;
            taxPayble = bracketAmout * 0.325 + 3572;
        }
        else if (this.salary > 90000 && this.salary <= 180000)
        {
            bracketAmout = this.salary - 90000;
            taxPayble = bracketAmout * 0.37 + 20797;

        }
        else if (this.salary > 180000)
        {
            bracketAmout = this.salary - 180000;
            taxPayble = bracketAmout * 0.45 + 54096;

        }
        else
        {
            taxPayble = 0;
        }
         return taxPayble.ToString("C"); 
    }
}

class EmployeeProgram
{
    static void Main()
    {
        // Under 17200
        Employee juan = new Employee("Juan", 15000);

        Employee james = new Employee("James", 100000);
        james.raiseSalary(200);
        james.tax();

        Console.WriteLine("Name: " + juan.getName() +
                         "\nSalary: " + juan.getSalary());
        Console.ReadLine();

        juan.raiseSalary(5);
        string taxPayble = juan.tax();

        Console.WriteLine("Name: " + juan.getName() +
                         "\nNew Salary: " + juan.getSalary() +
                         "\nTax:  " + taxPayble);
        Console.ReadLine();

        // between 17200 and 37000
        Employee albert = new Employee("Albert", 25000);

        Console.WriteLine("Name: " + albert.getName() +
                         "\nNew Salary: " + albert.getSalary() +
                         "\nTax:  " + albert.tax());
        Console.ReadLine();

        // between 37000 and 90000
        Employee sam = new Employee("Sam", 43000);

        Console.WriteLine("Name: " + sam.getName() +
                         "\nNew Salary: " + sam.getSalary() +
                         "\nTax:  " + sam.tax());
        Console.ReadLine();

        // between 90000 and 180000
        Employee tiff = new Employee("Tiff", 120000);

        Console.WriteLine("Name: " + tiff.getName() +
                         "\nNew Salary: " + tiff.getSalary() +
                         "\nTax:  " + tiff.tax());
        Console.ReadLine();

        // More than 180k
        Employee jhon = new Employee("Jhon", 210000);

        Console.WriteLine("Name: " + jhon.getName() +
                         "\nNew Salary: " + jhon.getSalary() +
                         "\nTax:  " + jhon.tax());
        Console.ReadLine();

    }
    


}
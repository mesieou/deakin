using System;

namespace OverloadingDemo
{
    public class Overloading
    {
        static void OverloadingMain(string[] args)
        {
            Console.WriteLine("=== Method Overloading Demonstration ===\n");

            // Call the first overloaded method with just a string parameter
            Console.WriteLine("Calling methodToBeOverloaded with one parameter:");
            methodToBeOverloaded("John");

            Console.WriteLine();

            // Call the second overloaded method with string and int parameters
            Console.WriteLine("Calling methodToBeOverloaded with two parameters:");
            methodToBeOverloaded("Alice", 25);

            Console.WriteLine("\nThe compiler automatically chooses the correct method based on the parameters provided!");
        }

        // First overloaded method - takes only a string parameter
        public static void methodToBeOverloaded(String name)
        {
            Console.WriteLine("Name: " + name);
        }

        // Second overloaded method - takes string and int parameters
        public static void methodToBeOverloaded(String name, int age)
        {
            Console.WriteLine("Name: " + name + "\nAge: " + age);
        }
    }
}

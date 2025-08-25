using System;

namespace InheritanceDemo
{
  public class ClassA
  {
    protected int i = 10;
  protected int Sum(int j)
  {
  return i + j;
  }
  public int Product(int j)
  {
  return i * j;
  }
  public virtual double Division(int j)
  {
  return i / j;
  }
}

public class ClassB : ClassA
{
  public override double Division(int j)
  {
  return (double)i / j;
  }
  public void PrintResults(int j)
  {
  Console.WriteLine("i: {0}", i);
  Console.WriteLine("Sum(j): {0}", Sum(j));
  Console.WriteLine("Product(j): {0}", Product(j));
  Console.WriteLine("Division(j): {0}", Division(j));
  }

  // Add a Main method to test the classes
  static void Main(string[] args)
  {
    ClassB objB = new ClassB();
    objB.PrintResults(5);
  }
}
}

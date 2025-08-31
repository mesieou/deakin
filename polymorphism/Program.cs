// See https://aka.ms/new-console-template for more information

class Program
{
  static void Main(string[] args)
  {
    Bird bird1 = new Bird();
    Bird bird2 = new Bird();

    bird1.name = "Tweety";
    bird2.name = "Polly";

    Console.WriteLine(bird1.ToString());
    bird1.Fly();

    Console.WriteLine(bird2.ToString());
    bird2.Fly();

    Console.ReadLine();
  }
}

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

    Penguin penguin1 = new Penguin();
    Penguin penguin2 = new Penguin();

    penguin1.name = "Pingu";
    penguin2.name = "Mumble";

    Console.WriteLine(penguin1.ToString());
    penguin1.Fly();

    Console.WriteLine(penguin2.ToString());
    penguin2.Fly();

    Duck duck1 = new Duck();
    Duck duck2 = new Duck();

    duck1.name = "Donald";
    duck1.size = 26.5;
    duck1.kind = "Mallard";

    duck2.name = "Daffy";
    duck2.size = 15.0;
    duck2.kind = "Black Duck";

    Console.WriteLine(duck1.ToString());
    Console.WriteLine(duck2.ToString());
  }
}

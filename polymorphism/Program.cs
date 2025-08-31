// See https://aka.ms/new-console-template for more information

class Program
{
  static void Main(string[] args)
  {
    List<Bird> birds = new List<Bird>();

    Bird bird1 = new Bird();
    bird1.name = "Tweety";
    Bird bird2 = new Bird();
    bird2.name = "Polly";

    Penguin penguin1 = new Penguin();
    penguin1.name = "Pingu";
    Penguin penguin2 = new Penguin();
    penguin2.name = "Mumble";

    Duck duck1 = new Duck();
    duck1.name = "Donald";
    duck1.size = 26.5;
    duck1.kind = "Mallard";
    Duck duck2 = new Duck();
    duck2.name = "Daffy";
    duck2.size = 15.0;
    duck2.kind = "Black Duck";

    birds.Add(bird1);
    birds.Add(bird2);
    birds.Add(penguin1);
    birds.Add(penguin2);
    birds.Add(duck1);
    birds.Add(duck2);

    birds.Add(new Bird() { name = "Birdy" });

    foreach (Bird bird in birds)
    {
      Console.WriteLine(bird);
    }

  }
}

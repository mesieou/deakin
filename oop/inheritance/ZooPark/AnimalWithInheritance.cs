using ZooPark;

namespace Task02
{
  public class Wolf : Animal
  {
    public Wolf(string name, string diet, string location, double weight, int age, string color)
        : base(name, diet, location, weight, age, color) { }

    public override void MakeNoise()
    {
      Console.WriteLine("howlllllll");
    }

    public override void Eat()
    {
      Console.WriteLine("I can eat up 10 lbs of meat");

    }

    public override void Sleep()
    {
      Console.WriteLine("I sleep 12 hours a day");
    }
  }

  public class Eagle : Bird
  {
    private String species;
    private Double wingSpan;
    public Eagle(string name, string diet, string location, double weight, int age, string color, string species, double wingSpan)
        : base(name, diet, location, weight, age, color, species)
    {
      this.species = species;
      this.wingSpan = wingSpan;
    }

    public override void Eat()
    {
      Console.WriteLine("I can eat up 1 lb of fish");

    }

    public override void MakeNoise()
    {
      Console.WriteLine("whistles");
    }
    public override void Sleep()
    {
      Console.WriteLine("I sleep 8 hours a day");
    }

    public void layEggs()
    {
    }

    public void Fly()
    {
    }
  }

  public class Tiger : Animal
  {
    private String species;
    private String colourStripes;
    public Tiger(string name, string diet, string location, double weight, int age, string color, string species, string colourStripes)
        : base(name, diet, location, weight, age, color)
    {
      this.species = species;
      this.colourStripes = colourStripes;
    }

    public override void MakeNoise()
    {
      Console.WriteLine("roaarrrrr");
    }

    public override void Eat()
    {
      Console.WriteLine("I can eat up 20 lbs of meat");
    }
    public override void Sleep()
    {
      Console.WriteLine("I sleep 6 hours a day");
    }

  }

  public class Lion : Feline
  {
    public Lion(string name, string diet, string location, double weight, int age, string color, string species, string colourStripes)
        : base(name, diet, location, weight, age, color, species, colourStripes)
    {
    }

    public override void MakeNoise()
    {
      Console.WriteLine("roarrrrrrrrr harder than a tiger");
    }

    public override void Eat()
    {
      Console.WriteLine("I can eat up 30 lbs of meat");
    }

    public override void Sleep()
    {
      Console.WriteLine("I sleep 5 hours a day");
    }
  }

  public class Penguin : Bird
  {
    public Penguin(string name, string diet, string location, double weight, int age, string color, string species, double wingSpan)
        : base(name, diet, location, weight, age, color, species)
    {
    }

    public override void MakeNoise()
    {
      Console.WriteLine("honk");
    }

    public override void Eat()
    {
      Console.WriteLine("I can eat up 1 lb of fish");
    }

    public override void Sleep()

    {
      Console.WriteLine("I sleep 12 hours a day");
    }
  }
}

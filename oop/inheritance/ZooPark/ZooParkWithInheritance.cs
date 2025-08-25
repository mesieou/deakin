
using Task02;

namespace ZooPark
{
  public class ZooPark
  {
    static void ZooParkMain(string[] args)
    {
      Wolf williamWolf = new Wolf("William the wolf", "Meat", "Dog Village", 50.6, 9, "Gray");
      Tiger tonyTiger = new Tiger("Tony the tiger", "Meat", "Cat Land", 110, 6, "Orange and White", "siberrian", "White");
      Eagle edgarEagle = new Eagle("Edgar the eagle", "Fish", "Bird Mania", 20, 5, "black", "Harpy", 98.5);
      Lion samsonLion = new Lion("Samson the lion", "Meat", "Savanna", 180, 8, "Golden", "African", "Dark brown");
      Penguin penguin = new Penguin("Penguin the penguin", "Fish", "Antarctica", 10, 3, "Black and White", "Emperor", 100);

      Animal baseAnimal = new Animal("Generic Animal", "Everything", "Nowhere", 0, 0, "Transparent");

      Console.WriteLine("=== Making Noise ===");
      baseAnimal.MakeNoise();
      williamWolf.MakeNoise();
      tonyTiger.MakeNoise();
      edgarEagle.MakeNoise();
      samsonLion.MakeNoise();
      penguin.MakeNoise();

      Console.WriteLine("\n=== Eating ===");
      baseAnimal.Eat();
      williamWolf.Eat();
      edgarEagle.Eat();
      tonyTiger.Eat();
      samsonLion.Eat();
      penguin.Eat();

      Console.WriteLine("\n=== Sleeping ===");
      baseAnimal.Sleep();
      williamWolf.Sleep();
      edgarEagle.Sleep();
      tonyTiger.Sleep();
      samsonLion.Sleep();
      penguin.Sleep();
    }
  }

  public class Animal  // Make public so other projects can access it
  {
    protected string name;
    protected string diet;
    protected string location;
    protected double weight;
    protected int age;
    protected string color;

    public Animal(string name, string diet, string location, double weight, int age, string color)
    {
      this.name = name;
      this.diet = diet;
      this.location = location;
      this.age = age;
      this.weight = weight;
      this.color = color;
    }

    public virtual void Eat()
    {
      Console.WriteLine("An anaimal is eating");
    }

    public virtual void Sleep()
    {
      Console.WriteLine(name + " is sleeping");
    }

    public virtual void MakeNoise()
    {
      Console.WriteLine(name + " is making noise");
    }
  }
}

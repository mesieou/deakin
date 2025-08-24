// See https://aka.ms/new-console-template for more information
class ZooPark
{
  static void Main(string[] args)
  {
    Animal williamWolf = new Animal("William the wolf", "Meat", "Dog Village", 50.6, 9, "Gray");
    Animal tonyTiger = new Animal("Tony the tiger", "Meat", "Cat Land", 110, 6, "Orange and White");
    Animal edgarEagle = new Animal("Edgar the eagle", "Fish", "Bird Mania", 20, 5, "black");
  }
}

class Animal
{
  private String name;
  private String diet;
  private String location;
  private Double weight;
  private int age;
  private String color;

  public Animal(string name, String diet, String location, Double weight, int age, String color)
  {
    this.name = name;
    this.diet = diet;
    this.location = location;
    this.age = age;
    this.weight = weight;
    this.color = color;
  }

  public void eat()
  {
    Console.WriteLine(name + " is eating " + diet);
  }

  public void sleep()
  {
    Console.WriteLine(name + " is sleeping");
  }

  public void makeNoise()
  {
    Console.WriteLine(name + " is making noise");
  }
}

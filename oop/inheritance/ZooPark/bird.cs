using ZooPark;

namespace Task02
{
  public class Bird : Animal
  {
    private String species;
    public Bird(string name, string diet, string location, double weight, int age, string color, string species)
        : base(name, diet, location, weight, age, color)
    {
      this.species = species;
    }
  }
}

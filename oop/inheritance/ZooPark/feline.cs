using ZooPark;

namespace Task02
{
  public class Feline : Animal
  {
    private String species;
    private String colourStripes;
    public Feline(string name, string diet, string location, double weight, int age, string color, string species, string colourStripes)
        : base(name, diet, location, weight, age, color)
    {
      this.species = species;
      this.colourStripes = colourStripes;
    }
  }
}

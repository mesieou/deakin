class Bird
{
  public String name { get; set; }

  public Bird()
  {

  }
  public virtual void Fly()
  {
    Console.WriteLine("Flap, Flap, Flap");
  }

  public override string ToString()
  {
    return $"A bird called {name}";
  }
}

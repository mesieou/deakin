using System;
using System.Text;

public class MyPolynomial
{
    // Instance variable: coefficients array
    private double[] _coeffs;

    // Constructor
    public MyPolynomial(double[] coeffs)
    {
        _coeffs = new double[coeffs.Length];
        Array.Copy(coeffs, _coeffs, coeffs.Length);
    }

    // Get the degree of the polynomial
    public int GetDegree()
    {
        return _coeffs.Length - 1;
    }

    // Return string representation
    public override string ToString()
    {
        StringBuilder sb = new StringBuilder();
        for (int i = _coeffs.Length - 1; i >= 0; i--)
        {
            double coeff = _coeffs[i];
            if (coeff == 0) continue; // Skip zero terms

            if (sb.Length > 0)
            {
                sb.Append(coeff > 0 ? " + " : " - ");
                coeff = Math.Abs(coeff);
            }
            else if (coeff < 0)
            {
                sb.Append("-");
                coeff = Math.Abs(coeff);
            }

            if (i == 0)
                sb.Append($"{coeff}");
            else if (i == 1)
                sb.Append($"{coeff}x");
            else
                sb.Append($"{coeff}x^{i}");
        }

        return sb.Length > 0 ? sb.ToString() : "0";
    }

    // Evaluate the polynomial for a given x
    public double Evaluate(double x)
    {
        double result = 0;
        for (int i = 0; i < _coeffs.Length; i++)
        {
            result += _coeffs[i] * Math.Pow(x, i);
        }
        return result;
    }

    // Add another polynomial
    public MyPolynomial Add(MyPolynomial another)
    {
        int maxLength = Math.Max(_coeffs.Length, another._coeffs.Length);
        double[] newCoeffs = new double[maxLength];

        for (int i = 0; i < maxLength; i++)
        {
            double coeff1 = i < _coeffs.Length ? _coeffs[i] : 0;
            double coeff2 = i < another._coeffs.Length ? another._coeffs[i] : 0;
            newCoeffs[i] = coeff1 + coeff2;
        }

        _coeffs = newCoeffs;
        return this;
    }

    // Multiply by another polynomial
    public MyPolynomial Multiply(MyPolynomial another)
    {
        int newDegree = _coeffs.Length + another._coeffs.Length - 2;
        double[] newCoeffs = new double[newDegree + 1];

        for (int i = 0; i < _coeffs.Length; i++)
        {
            for (int j = 0; j < another._coeffs.Length; j++)
            {
                newCoeffs[i + j] += _coeffs[i] * another._coeffs[j];
            }
        }

        _coeffs = newCoeffs;
        return this;
    }
}

class TestMyPolynomial
{
    static void Main(string[] args)
    {
        // Create polynomials
        MyPolynomial p1 = new MyPolynomial(new double[] { 1, 0, 6, 0, 8 }); // 8x^4 + 6x^2 + 1
        MyPolynomial p2 = new MyPolynomial(new double[] { 0, 2, 0, 5 });    // 5x^3 + 2x

        Console.WriteLine("Polynomial p1: " + p1);
        Console.WriteLine("Polynomial p2: " + p2);

        // Test GetDegree
        Console.WriteLine("Degree of p1: " + p1.GetDegree());

        // Test Evaluate
        double x = 2;
        Console.WriteLine($"p1({x}) = " + p1.Evaluate(x));

        // Test Add
        MyPolynomial sum = new MyPolynomial(new double[] { 1, 0, 6, 0, 8 }); // copy of p1
        sum.Add(p2);
        Console.WriteLine("p1 + p2 = " + sum);

        // Test Multiply
        MyPolynomial prod = new MyPolynomial(new double[] { 1, 0, 6, 0, 8 }); // copy of p1
        prod.Multiply(p2);
        Console.WriteLine("p1 * p2 = " + prod);
    }
}

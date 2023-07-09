public class Fraction {
  // Instance variables
  private int numerator;    // Numerator of fraction
  private int denominator;  // Denominator of fraction

  public Fraction(int num, int denom) {  // Constructor 1
    numerator = num;
    denominator = denom;
    reduce();
  }

  public Fraction(int num) {             // Constructor 2
    this(num, 1);
  }

  public Fraction() {                    // Constructor 3
    this(0, 1);
  }

  public Fraction add(Fraction f) {
    int num = numerator * f.denominator +
              f.numerator * denominator;
    int denom = denominator * f.denominator;
    return new Fraction(num, denom);
  }

  public Fraction divide(Fraction f) {
    int num = numerator * f.denominator;
    int denom = denominator * f.numerator;
    return new Fraction(num, denom);
  }

  public int getDenominator() {
    return denominator;
  }

  public int getNumerator() {
    return numerator;
  }

  public Fraction multiply(Fraction f) {
    int num = numerator * f.numerator;
    int denom = denominator * f.denominator;
    return new Fraction(num, denom);
  }

  public Fraction subtract(Fraction f) {
    int num = numerator * f.denominator -
              f.numerator * denominator;
    int denom = denominator * f.denominator;
    return new Fraction(num, denom);
  }

  public double toDouble() {
    return (double) numerator / denominator;
  }

  public float toFloat() {
    return (float) numerator / denominator;
  }

  public String toString() {
    if (denominator == 1)
      return numerator + "";
    else
      return numerator + "/" + denominator;
  }

  private void reduce() {
    int g = gcd(numerator, denominator);

    if (g != 0) {
      numerator /= g;
      denominator /= g;
    }

    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
  }

  private static int gcd(int m, int n) {
    while (n != 0) {
      int r = m % n;
      m = n;
      n = r;
    }
    return m;
  }
}

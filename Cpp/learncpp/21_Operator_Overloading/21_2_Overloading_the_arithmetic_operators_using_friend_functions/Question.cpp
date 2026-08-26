#include <iostream>
#include <numeric>

// A simple fraction type that supports multiplication with other fractions
// and with integers on either side of the operator.
class Fraction {
  private:
    int m_denomitor;  // denominator of the fraction
    int m_numerator;  // numerator of the fraction

  // Reduce the fraction by dividing both numerator and denominator by their gcd.
  // This keeps the representation in its simplest form.
    void Reduce(){
      int gcd{std::gcd(m_numerator, m_denomitor)};
      if (gcd){
        m_denomitor /= gcd;
        m_numerator /= gcd;
      }
    }

  public:
    // Constructor: create a Fraction from a numerator and optional denominator.
    // The denominator defaults to 1, which makes integers behave like fractions.
    explicit Fraction(int numerator, int denomitor=1): m_numerator(numerator), m_denomitor(denomitor){
      Reduce();
    }

    // Print the fraction in the format numerator/denominator.
    void print(){
      std::cout << m_numerator << "/" << m_denomitor << '\n';
    }

    // Multiply a fraction by an integer on the right.
    friend Fraction operator*(const Fraction& first, const int& second){
      return Fraction{first.m_numerator*second, first.m_denomitor};
    }

    // Multiply an integer by a fraction on the left.
    friend Fraction operator*(const int& first, const Fraction& second){
      return Fraction{second*first};
    }

    // Multiply one fraction by another fraction.
    friend Fraction operator*(const Fraction& first, const Fraction& second){
        return Fraction{first.m_numerator*second.m_numerator, first.m_denomitor*second.m_denomitor};
    }
};

  int main() {
    // Create a few fractions to demonstrate multiplication.
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{f1*f2};
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{2*f2};
    f5.print();

    Fraction f6{ Fraction{1, 2}*Fraction{2, 3}*Fraction{3, 4}};
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}

#include <iostream>

// Defines a class to represent and operate on mathematical fractions
class Fraction{
private:
// Member variables to store the numerator and denominator
// Initialized with default values
int m_numerator{ 0 };
int m_denominator{ 1 };

public:
// Default constructor using the default implementation
Fraction() = default;

// Member function to get fraction values from user input
void getFraction() {

  std::cout << "Enter a value for numerator: ";
  std::cin >> m_numerator;
  std::cout << "Enter a value for denominator: ";
  std::cin >> m_denominator;
  std::cout << '\n';

}

// Member function to multiply this fraction with another fraction
// Returns a new fraction containing the result
// Marked const as it doesn't modify the original fractions
Fraction multiply(const Fraction& f2) const {

  Fraction fractionholder;
// Multiply numerators and denominators separately
  fractionholder.m_denominator = m_denominator * f2.m_denominator;
  fractionholder.m_numerator = m_numerator * f2.m_numerator;

return fractionholder;
}

// Member function to print the fraction in the format "numerator/denominator"
// Marked const as it doesn't modify the fraction
const void printFraction() const {
  std::cout << m_numerator << '/' << m_denominator << '\n';
}

};

int main()
{
// Create and get input for first fraction
Fraction f1{};
f1.getFraction();

// Create and get input for second fraction
Fraction f2{};
f2.getFraction();

std::cout << "Your fractions multiplied together: ";

// Multiply the fractions and print the result
// Demonstrates function chaining: multiply() returns a Fraction, then printFraction() is called on the result
f1.multiply(f2).printFraction();

return 0;
}
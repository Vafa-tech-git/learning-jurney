#include <iostream>

// Defines a structure to represent a fraction
struct Fraction{

  int numerator{0};
  int denominator{1};
  
};

// Function to get a fraction from the user
Fraction input(){

  Fraction fraction{};

  std::cout << "Enter a value for the numerator: ";
  std::cin >> fraction.numerator;
  std::cout << "Enter a value for the denominator: ";
  std::cin >> fraction.denominator;

return fraction;
}

// Function to multiply two fractions
constexpr Fraction Fmult(const Fraction& firstfraction, const Fraction& secondfraction){

  Fraction fmultrezult{};

  fmultrezult.numerator = firstfraction.numerator * secondfraction.numerator;
  fmultrezult.denominator = firstfraction.denominator * secondfraction.denominator;

return fmultrezult;
}

// Function to print a fraction
void printfraction(Fraction functionprint){

std::cout << "Your fractions multiplied together: " << functionprint.numerator << '/' << functionprint.denominator;

}


int main(){

// Gets two fractions from the user, multiplies them, and prints the result
printfraction(Fmult(input(), input()));

return 0;
}
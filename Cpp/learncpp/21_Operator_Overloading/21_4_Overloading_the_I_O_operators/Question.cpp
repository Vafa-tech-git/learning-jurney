#include <iostream>
#include <numeric> // for std::gcd

// A simple Fraction class that stores a numerator and denominator
// and supports arithmetic plus stream I/O operations.
class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	// Construct a fraction; defaults to 0/1. Reduce to lowest terms on creation.
	Fraction(int numerator=0, int denominator=1)
		: m_numerator{numerator}, m_denominator{denominator}
	{
		reduce();
	}

	// Reduce the fraction to its simplest form using the GCD.
	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	// Multiplication operators are friends so they can access private members.
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);

	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}

	// Output operator: prints as "numerator/denominator".
	friend std::ostream& operator<<(std::ostream& out, Fraction fraction)
	{
		out << fraction.m_numerator << '/' << fraction.m_denominator;
		return out;
	}

	// Input operator: expects input like "numerator/denominator".
	// If the denominator is zero, the stream is marked as failed.
	friend std::istream& operator>>(std::istream& in, Fraction& fraction)
	{
		int denominator{};
		char ignore{};
		int numerator{};

		in >> numerator >> ignore >> denominator;
		if (denominator == 0){
			in.setstate(std::ios_base::failbit);
			return in;
		}
		if(in){
			fraction.m_numerator = numerator;
			fraction.m_denominator = denominator;
			// Normalize the fraction after reading valid input.
			fraction.reduce();
		}

		return in;
	}
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction{ f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction{ f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1)
{
	return Fraction{ f1.m_numerator * value, f1.m_denominator };
}

int main()
{
	Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	// This prints the multiplication result using the overloaded stream operator.
	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

	return 0;
}
#include <iostream>
#include <numeric> // for std::gcd

// A fraction type that stores a numerator and denominator
// and supports comparison operators.
class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	// Construct a fraction and automatically normalize it.
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator{ numerator }, m_denominator{ denominator }
	{
		// We reduce the fraction in the constructor so any newly created
		// fraction is always stored in lowest terms.
		reduce();
	}

	// Reduce the fraction using the greatest common divisor.
	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	// Declare comparison and stream operators as friends so they can access
	// the private numerator and denominator members.
	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
	friend bool operator==(const Fraction& f1, const Fraction& f2);
	friend bool operator!=(const Fraction& f1, const Fraction& f2);
	friend bool operator<(const Fraction& f1, const Fraction& f2);
	friend bool operator>(const Fraction& f1, const Fraction& f2);
	friend bool operator<=(const Fraction& f1, const Fraction& f2);
	friend bool operator>=(const Fraction& f1, const Fraction& f2);
};

// Print the fraction in the form numerator/denominator.
std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

// Two fractions are equal only if both numerator and denominator match.
bool operator==(const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator);
}

// Not equal is the inverse of equality.
bool operator!=(const Fraction& f1, const Fraction& f2)
{
	return !(operator==(f1, f2));
}

// Compare fractions using cross multiplication.
// a/b < c/d is equivalent to a*d < c*b when denominators are positive.
bool operator<(const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator * f2.m_denominator < f2.m_numerator * f1.m_denominator);
}

// Greater-than can be implemented in terms of less-than.
bool operator>(const Fraction& f1, const Fraction& f2)
{
	return operator<(f2, f1);
}

// Less-than-or-equal is the opposite of greater-than.
bool operator<=(const Fraction& f1, const Fraction& f2)
{
	return !(operator>(f1, f2));
}

// Greater-than-or-equal is the opposite of less-than.
bool operator>=(const Fraction& f1, const Fraction& f2)
{
	return !(operator<(f1, f2));
}

int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	return 0;
}
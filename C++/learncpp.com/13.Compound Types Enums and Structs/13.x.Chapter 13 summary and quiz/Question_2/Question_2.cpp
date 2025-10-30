#include <iostream>

// Defines a template for a struct that holds three values of the same type
template <typename t>
struct triad{

  t first;
  t second;
  t third;

};

// Deduction guide for the triad struct
template <typename t>
triad(t, t, t) -> triad<t>;

// Template function to print the values of a triad
template <typename t>
void print(const triad<t>& numberprint){

  std::cout << "[" << numberprint.first << ", " << numberprint.second << ", " << numberprint.third << "]";

}


int main()
{
// Creates a triad of integers
	triad t1{ 1, 2, 3 };
// Prints the triad of integers
	print(t1);

// Creates a triad of doubles
	triad t2{ 1.2, 3.4, 5.6 };
// Prints the triad of doubles
	print(t2);

	return 0;
}
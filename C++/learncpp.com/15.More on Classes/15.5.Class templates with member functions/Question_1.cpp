#include <iostream>
#include <string>

// A class template named 'Triad' that holds three values of potentially different types.
// The template parameters var1, var2, var3 represent the types of the first, second and third members.
template <typename var1, typename var2, typename var3>
class Triad{

private:
// Member variables to store the three values.
var1 m_first;
var2 m_second;
var3 m_third;

public:

// Constructor that initializes all three members using a member initializer list.
Triad(const var1& first, const var2& second, const var3& third) : m_first{first}, m_second{second}, m_third{third}{
}

// Getter for the first element (returns a copy).
var1 first() const { return m_first; }
// Setter for the first element (assigns from the provided value).
void setfirst(var1& first) { m_first = first; }

// Getter for the second element (returns a copy).
var2 second() const { return m_second; }
// Setter for the second element.
void setsecond(var2& second) { m_second = second; }

// Getter for the third element (returns a copy).
var3 third() const { return m_third; }
// Setter for the third element.
void setthird(var3& third) { m_third = third; }

// Declaration of a member function that prints the triad contents.
void print() const;

};

// Definition of the print member function outside the class template.
// Uses the template parameter names and the fully qualified name for the member function.
template <typename var1, typename var2, typename var3>
void Triad<var1, var2, var3>::print() const {
std::cout << "[" << m_first << ", " << m_second << ", " << m_third << "]";
}

int main(){
// Example: all three elements are ints
  Triad<int, int, int> t1{ 1, 2, 3 };
  t1.print();
  std::cout << '\n';
  std::cout << t1.first() << '\n';

// Example: mix of int, double and std::string
  using namespace std::literals::string_literals;
  const Triad<int, double, std::string> t2{ 1, 2.3, "Hello"s };
  t2.print();
  std::cout << '\n';

  return 0;
}
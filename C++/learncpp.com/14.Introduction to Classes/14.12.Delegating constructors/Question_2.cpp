#include <iostream>
#include <string>

// Defines a class named 'ball' to represent a ball with a color and radius.
class ball{

private:
// Private member variable to store the color of the ball. Initialized to "black".
  std::string m_color{"black"};
// Private member variable to store the radius of the ball. Initialized to 10.0.
  double m_radius{10.0};

// A private member function to print the ball's properties.
// This is used by the constructors to show when a ball is created.
  void constructorprint() const {
    std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
  }

public:
// A delegating constructor that takes only the radius.
// It calls the other constructor with a default color "black".
  ball(const double& radius) : ball("black", radius)
  {}

// The main constructor that initializes color and radius.
// It has default values for both parameters.
// It calls constructorprint() to show the object's state upon creation.
  ball(const std::string& color = "black", const double& radius = 10.0) : m_color{color}, m_radius{radius}
  { constructorprint(); }

};

int main()
{
// Creates a ball object with default color and radius.
  ball def{};
// Creates a ball object with color "blue" and default radius.
  ball blue{ "blue" };
// Creates a ball object with radius 20.0 and default color.
  ball twenty{ 20.0 };
// Creates a ball object with color "blue" and radius 20.0.
  ball blueTwenty{ "blue", 20.0 };

return 0;
}
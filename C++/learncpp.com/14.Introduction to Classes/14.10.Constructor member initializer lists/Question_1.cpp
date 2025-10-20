#include <iostream>
#include <string>
#include <string_view>

// Defines a class named 'ball' to represent a ball with a color and radius.
class ball{

private:
// Private member variable to store the color of the ball. Initialized to "none".
  std::string m_color { "none" };
// Private member variable to store the radius of the ball. Initialized to 0.0.
  double m_radius { 0.0 };

public:
// Constructor for the 'ball' class that initializes the color and radius using a member initializer list.
// It takes a string_view for the color and a double for the radius as arguments.
  ball(std::string_view colorcon, double radiuscon) : m_color{colorcon}, m_radius{radiuscon}{

  };

// Getter function that returns a reference to the color of the ball.
  std::string& getcolor() { return m_color; }
// Getter function that returns a reference to the radius of the ball.
  double& getradius() { return m_radius; }

};

// A function to print the details of a ball object (color and radius).
void print(ball& ballprint){

// Outputs the ball's color and radius to the console.
std::cout << "Ball(" << ballprint.getcolor() << ", " << ballprint.getradius() << ")\n";

}


int main()
{

// Creates an instance of the 'ball' class named 'blue' with color "blue" and radius 10.0.
ball blue { "blue", 10.0 };
// Calls the 'print' function to display the details of the 'blue' ball.
print(blue);

// Creates another instance of the 'ball' class named 'red' with color "red" and radius 12.0.
ball red { "red", 12.0 };
// Calls the 'print' function to display the details of the 'red' ball.
print(red);

return 0;
}
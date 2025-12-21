#include <iostream>
#include <vector>
#include <cassert>
#include <string>


// Namespace to group related animal types
namespace Species{
  // Enum to represent different animal species
  enum Animals{
    Chicken,
    Dog,
    Cat,
    Elephant,
    Duck,
    Snake,
    maxanimal 
    // Used to represent the count of animals
  };
}


// Function to convert enum value to animal name string
std::string AnimalReturn(Species::Animals animal){
  switch (animal){
    case Species::Chicken : return "Chicken";
    case Species::Dog : return "Dog";
    case Species::Cat : return "Cat";
    case Species::Elephant : return "Elephant";
    case Species::Duck : return "Duck";
    case Species::Snake : return "Snake";
    default : return "N/N";
  }
}

int main(){
  // Vector storing the number of legs for each animal
  const std::vector legs {2, 4, 4, 4, 2, 0};

  // Ensure the vector size matches the number of animals in the enum
  assert(Species::maxanimal==legs.size());

  // Print the number of legs for the Elephant
  std::cout << "An " << AnimalReturn(Species::Elephant) << " has " << legs[Species::Elephant] << " legs.";


return 0;
}
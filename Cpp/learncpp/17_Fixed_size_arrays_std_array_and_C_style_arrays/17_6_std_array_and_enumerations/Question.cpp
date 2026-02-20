#include <iostream>
#include <string_view>
#include <array>

using namespace std::literals::string_view_literals;

// Namespaces organize settings and data
namespace Animal{

  enum Species{
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    max_animals
  };

  // Struct members represent the data state
  struct Data{
    const std::string_view name;
    const short legs;
    const std::string_view sound;
  };

  // Using std::string_view within the array for memory efficiency [1]
  const std::array <Data, max_animals> animal{
    {
      {"Chicken"sv, 2, "cluck"sv},
      {"Dog"sv, 4, "bark"sv},
      {"Cat"sv, 4, "meow"sv},
      {"Elephant"sv, 4, "growl"sv},
      {"Duck"sv, 2, "quack"sv},
      {"Snake"sv, 0, "hiss"sv}
    }
  }; 

}

std::string UserInput(){

  std::string input{};

  std::cout << "Enter an animal: ";
  std::cin >> input;

return input;
}

// Returns std::pair with the bool value and the indices.
std::pair<bool, std::size_t> FindAnimal(std::string_view input){

  const std::array<Animal::Data, Animal::max_animals>& names = Animal::animal;

  // Indexed loop compares player input to the data
  for ( std::size_t index{0}; index < Animal::max_animals; index++){
    if (input == names[index].name){
      return {true, index};
    }
  }

return {false, 0uz};
}

// Handles output formatting based on game state or search results
void Draw(const bool found, std::size_t index){

  // Conditional output based on game rules or search status
  if (found){
    std::cout << "A " << Animal::animal[index].name << " has " << Animal::animal[index].legs <<  " and says " << Animal::animal[index].sound << "\n\n";
  }
  else{
    std::cout << "Animal not found\n";
    return;
  }

  std::cout << "Here is the data for the rest of the animals:\n";

  // Range-based loop for iterating through the collection excludin the one the user gave
  for (const auto& element : Animal::animal){
    if (element.name != Animal::animal[index].name){
      std::cout << "A " << element.name << " has " << element.legs << " and says " << element.sound << '\n';
    }
    else{
      continue;
    }
  }

}

int main(){

  // Save the input and the indices and bool value of the input logic.
  std::pair <bool, std::size_t> animal_found{FindAnimal(UserInput())};

  //Draw the state of the game
  Draw(animal_found.first, animal_found.second);

return 0;
}
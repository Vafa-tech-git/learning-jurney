#include <iostream>
#include <string_view>


// Define an enum class named Animal
// It contains a list of animals
enum class Animal{

  pig,
  chicken,
  goat,
  cat,
  dog,
  duck

};

// This function takes an Animal enum and returns its name as a string_view
std::string_view getAnimalName(Animal animalname){

// Use a switch statement to return the correct name for each animal
  switch (animalname){
    case Animal::pig : return "pig";
    case Animal::chicken : return "chicken";
    case Animal::goat : return "goat";
    case Animal::cat : return "cat";
    case Animal::dog : return "dog";
    case Animal::duck : return "duck";
    default : return "???"; // Return "???" for any unknown animal
  }

}

// This function takes an Animal enum and returns the number of legs for that animal
std::string_view printnumberoflegs(Animal animalprint){

// Use a switch statement to return the number of legs for each animal
  switch (animalprint){
    case Animal::pig : return "4";
    case Animal::chicken : return "2";
    case Animal::goat : return "4";
    case Animal::cat : return "4";
    case Animal::dog : return "4";
    case Animal::duck : return "2";
    default : return "???"; // Return "???" for any unknown animal
  }
}

int main(){

// Print the name of a cat and the number of legs it has
  std::cout << "A " << getAnimalName(Animal::cat) << " has " << printnumberoflegs(Animal::cat) << " legs\n";
// Print the name of a chicken and the number of legs it has
  std::cout << "A " << getAnimalName(Animal::chicken) << " has " << printnumberoflegs(Animal::chicken) << " legs\n";

return 0;
}
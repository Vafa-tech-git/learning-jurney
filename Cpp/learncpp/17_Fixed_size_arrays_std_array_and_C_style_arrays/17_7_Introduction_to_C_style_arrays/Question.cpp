#include <iostream>
#include <limits>

// Namespaces organize data
namespace Data{
  int squares[] {0, 1, 4, 9};
  int input{};
}

// User input with basic input validation
void UserInput(){

  std::cin >> Data::input;

  if (!std::cin){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input\n";
  }

}

// Returns bool with the bool value if the input is in the squares vector
bool Found(){

  for (const char& element : Data::squares){
    if (Data::input == element){
      return true;
    }
  }

return false;
}

// Handels output formatting based on game state or user input
void draw(){

  do{

    std::cout << "Enter a single digit integer, or -1 to quit: ";

    UserInput();

    if (Data::input <= 0 || Data::input > 10){
      continue;
    }

    if (Found()){
      std::cout << Data::input << " is a perfect square\n";
    }
    else{
      std::cout << Data::input << " is not a perfect square\n";
    }

  } while (Data::input != -1);

  if (Data::input == -1){
    std::cout << "Bye";
  }

}

int main(){

  draw();

}
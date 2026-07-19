#include <algorithm>
#include <iostream>
#include <string>

int main(){
  int length; // Stores how many names the user wants to enter.

  std::cout << "How many names would you like to enter? ";
  std::cin >> length;

  std::string* array{new std::string[length]{}};
  for (int i{0}; i<length; i++){
    std::cout << "Enter name #" << i+1 << ": ";
    std::getline(std::cin >> std::ws, array[i]); // Reads each name, including spaces.
  }

  std::sort(array, array+length); // Sorts the names alphabetically.

  std::cout << "Here is your sorted list:\n";
  for (int i{0}; i<length; i++){
    std::cout << "Name #" << i+1 << ": " << array[i] << '\n'; // Prints each sorted name.
  }

  delete array; // Frees the dynamically allocated memory.

return 0;
}
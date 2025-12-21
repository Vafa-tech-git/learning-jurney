#include <iostream>
#include <string_view>
#include <string>
#include <vector>

using namespace std::literals::string_view_literals;

// Template function to search for a name in a vector
// Returns true if the name is found, false otherwise
template <typename Names, typename Input>
bool FindName(const std::vector<Names>& names, const Input& userinput){
  // Use a range-based for loop to iterate through the vector
  for (std::string_view trough : names){
    if (userinput==trough){
      return true;
    }
  }
  return false;
}


int main(){

  // Vector of names using string_view literals
  const std::vector names{"Alex"sv, "Betty"sv, "Caroline"sv, "Dave"sv, "Emily"sv, "Fred"sv, "Greg"sv, "Holly"sv};

  std::string userinput{};

  std::cout << "Enter a name: ";
  std::cin >> userinput;

  std::cout << userinput << " was ";

  if (FindName(names, userinput)){
    std::cout << "found.";
  }
  else{
    std::cout << "not found.";
  }

  return 0;
}
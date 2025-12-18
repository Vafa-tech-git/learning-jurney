#include <iostream>
#include <limits>
#include <vector>


// Function to get a valid user input between 1 and 9
double UserInput(){

double value;

  do{
    std::cout << "Enter a number between 1 and 9: ";
    std::cin >> value;
    // If input is invalid, clear error and ignore the rest of the line
    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while( value <1|| value>9); 
  // Repeat until valid input

return value;
}


// Template function to print all elements of a vector
template <typename ArrSearch>
const void VectorPrint(const std::vector<ArrSearch>& arr){
  for (std::size_t index{0}; index<arr.size(); index++){
    std::cout << arr[index] << " ";
  }
  std::cout << '\n';
}


// Template function to search for a value in a vector
// Returns the index if found, otherwise returns arr.size()+1
template <typename ArrType>
auto SearchArrF(const auto& userinput, const std::vector<ArrType>& arr){
  std::size_t index{};
  for (index=0; index<arr.size(); index++){
    if ( arr[index]==userinput ){
      return index;
    }
  }
  return index+1;
}


// Template function to print the result of the search
template <typename ArrType>
void IndexPrint(const auto& indexver, const double& varver, const std::vector<ArrType>& vectorver){
  std::cout << "The number " <<  varver;
  if (vectorver[indexver]==varver){
    std::cout << " has index " << indexver;
  }
  else {
    std::cout << " has not been found.";
  }
}

int main(){


  // Get user input between 1 and 9
  const double input{UserInput()};
  // Vector of numbers to search
  const std::vector<double> arr{4, 6, 7, 3, 8, 2, 1, 9, 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9};
  // Search for the input in the vector and get the index
  const std::size_t index{static_cast<std::size_t>(SearchArrF(input, arr))};

  // Print the vector
  VectorPrint(arr);
  // Print the search result
  IndexPrint(index, input, arr);

return 0;
}
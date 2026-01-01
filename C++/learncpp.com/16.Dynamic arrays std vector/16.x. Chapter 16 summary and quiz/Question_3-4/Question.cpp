#include <iostream>
#include <limits>
#include <vector>



// Returns the indices of the min and max elements in the array
template <typename Vtype>
std::pair<std::size_t, std::size_t> Value(const std::vector<Vtype>& array){

  std::size_t min_index{0};
  std::size_t max_index{0};

  for (int i = 0; i < array.size(); i++){

    if (array[i] > array[max_index]){
      max_index = i;
    }

    if (array[i] < array[min_index]){
      min_index = i;
    }

  }

return {min_index, max_index};
}



// Prints the array and the min/max index and value
template <typename T>
void Print(const std::vector<T>& array, const std::size_t& min_index, const std::size_t& max_index){

  bool comma{false};

  std::cout << "With array ( ";

  for (const auto& element : array){

    if (comma){
      std::cout << ", ";
    }

    std::cout << element;
    comma = true;

  }

  std::cout << " ):\n";
  std::cout << "The min element has index " << min_index << " and value " << array[min_index] << '\n';
  std::cout << "The max element has index " << max_index << " and value " << array[max_index] << '\n';
}


// Clears input stream if input is invalid
void InputValidation(){

  if (!std::cin){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

}


// Reads user input into a vector, stops at -1 (not allowed as first input)
template <typename Input>
std::vector<Input> UserInput(){

  std::vector<Input> array;
  Input user_i{};

  std::cout << "Enter numbers to add (use -1 to stop): ";

  do{

    std::cin >> user_i;

    InputValidation();

    array.push_back(user_i);

    if (array[0] == -1){
      std::cout << "Can't give -1 first. Try again: ";
      array.pop_back();
      continue;
    }

  } while (array.back() != -1);

  if (array.back() == -1){
    array.pop_back();
  }

return array;
}


int main(){

  // Get user input
  std::vector<int> array = UserInput<int>();

  // Find min and max indices
  const std::pair<std::size_t, std::size_t> array_index = Value(array);

  // Print results
  Print(array, array_index.first, array_index.second);

return 0;
}

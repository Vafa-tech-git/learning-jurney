#include <iostream>
#include <vector>

// A template function that can work with vectors of any type.
template <typename vectortype>
// The function takes a vector by constant reference (for efficiency and safety)
// and an index of type std::size_t (an unsigned integer type, appropriate for indexing).
void printElement(const std::vector<vectortype>& vector, std::size_t index){
// Check if the index is out of the valid bounds.
// Valid indices are from 0 to vector.size() - 1.
if (index >= vector.size()) {std::cout << "Invalid index\n"; // Print a message if the index is invalid.
} 
else{
// If the index is valid, print the value of the element at that index.
std::cout << "The element has value: " << vector[index] << '\n';
}

}

int main()
{
  // Create and print vector of integers.
  std::vector<int> v1 { 0, 1, 2, 3, 4 };
  printElement(v1, 2);
  printElement(v1, 5);

  // Create and print vector of doubles.
  std::vector<double> v2 { 1.1, 2.2, 3.3 };
  printElement(v2, 0);
  printElement(v2, -1);

return 0;
}
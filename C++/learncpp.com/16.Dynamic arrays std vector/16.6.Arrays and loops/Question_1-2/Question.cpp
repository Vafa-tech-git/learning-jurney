#include <iostream>
#include <vector>

// A template function that can work with vectors of any type.
template <typename T>
// A function that prints every element of the container of any type.
void printArray(const std::vector<T>& arr)
{
  for (std::size_t index{ 0 }; index < arr.size(); ++index){
        std::cout << arr[index] << ' ';
  }
// Verify if the size of the container is negative.
  if (arr.size() > 0)
    std::cout << '\n';
}

int main()
{
  std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

  printArray(arr);

  return 0;
}
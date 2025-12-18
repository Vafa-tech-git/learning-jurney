#include <iostream>
#include <vector>


// Template function to find the maximum value in a vector
template <typename MaxValue>
MaxValue findMax(const std::vector<MaxValue>& data){
  // If the vector is empty, return a default-constructed value
  if (data.empty()){
    return MaxValue{};
  }

  // Initialize max_value with the first element
  MaxValue max_value{data[0]};

  // Loop through the vector to find the maximum value
  for (int i{}; i<data.size(); i++){
    if (data[i]>max_value){
      max_value = data[i];
    }
  }

  return max_value;
}

int main()
{
  // Integer vector example
  const std::vector data1 { 84, 92, 76, 81, 56 };
  std::cout << findMax(data1) << '\n';

  // Double vector example
  const std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
  std::cout << findMax(data2) << '\n';

  // Empty vector example
  const std::vector<int> data3 { };
  std::cout << findMax(data3) << '\n';

  return 0;
}
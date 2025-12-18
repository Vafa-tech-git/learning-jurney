#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>

int main(){


  // List of divisors to check for each number
  const std::vector<int> divisors {3, 5, 7, 11, 13, 17, 19};
  // Corresponding words to print if divisible
  const std::vector<std::string_view> words {"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};


  // Ensure both vectors have the same size for correct mapping
  assert(divisors.size()==words.size());


  // Loop through numbers 1 to 150
  for (int i{1}; i<=150; i++){
    int index{0};
    // Tracks if any word was printed
    bool foundWord{false};

    // Check divisibility for each divisor
    for (index=0; index<divisors.size(); index++){
      if (i%divisors[index]==0){
        // If divisible, print the corresponding word
        std::cout << words[index];
        foundWord = true;
      }
    }

    // If not divisible by any, print the number itself
    if (!foundWord){
      std::cout << i;
    }

    // Print newline after each output
    std::cout << '\n';
  }


return 0;
}
#include <vector>
#include <iostream>

// Function to calculate Factorial using recursion
int FactorialInteger(int number){
  // Base cases: if number is 0 or 1
  if (number == 0){
    return 0;
  }
  if (number == 1){
    return 1;
  }

  // Local cache (recreated in each recursive call)
  std::vector cache{0, 1};

  if (number < cache.size()){
    return cache[number];
  }

  cache.push_back(number);

// Recursive step: n * (n-1)!
return FactorialInteger(number-1) * number;
}

int sumOfIndividualLetter(int number){
  if (number <= 10){
    return number;
  }

return sumOfIndividualLetter(number/10) + number%10;
}

void binaryNumber(unsigned int number){

  if(number > 1){
	  binaryNumber(number / 2);
  }

	std::cout << number % 2;
}

int main(){
	int x{};
	std::cout << "Enter an integer: ";
	std::cin >> x;

	binaryNumber(static_cast<unsigned int>(x));
}
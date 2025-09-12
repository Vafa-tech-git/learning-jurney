#include <iostream>

// Function to get user input from standard input
int userinput()
{
  int value;

  std::cin >> value; 
  
return value;      
}

// Function to calculate the sum of all numbers from 1 to uservalue
int sumto(int uservalue)
{
  int total{0}; // Initialize total sum to 0

  // Loop from 1 up to uservalue, inclusive
  for (int sumedtotal{1}; sumedtotal <= uservalue; sumedtotal++)
  {
    total += sumedtotal; // Add current number to total
  }
 
  return total;
}

int main()
{
  // Prompt user and print the sum of numbers up to the entered value
  std::cout << "Sum of every number up to: " << sumto(userinput()) << '\n';

  return 0;  
}
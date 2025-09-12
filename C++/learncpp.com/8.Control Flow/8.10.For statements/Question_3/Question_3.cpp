#include <iostream>
#include <string>

// Function to print fizzbuzz, fizz, buzz, pop, or the number up to countlimit
void fizzbuzz(int countlimit)
{
   // Loop from 1 to countlimit
   for (int count{1}; count <= countlimit; ++count )
   {
      // If divisible by both 3 and 5, print "fizzbuzz"
      if ( count % 3 == 0 && count % 5 == 0 )
      {
        std::cout << "fizzbuzz\n";
      }
      // If divisible by 3 only, print "fizz"
      else if ( count % 3 == 0 )
      {
        std::cout << "fizz\n";
      }
      // If divisible by 5 only, print "buzz"
      else if ( count % 5 == 0 )
      {
        std::cout << "buzz\n"; 
      }
      // If divisible by 7 only, print "pop"
      else if ( count % 7 == 0)
      {
        std::cout << "pop\n";
      }
      // Otherwise, print the number
      else
      {
        std::cout << count << '\n';
      }
   }
}

int main()
{
  int value;                // Variable to store the upper limit
  std::string userinput;    // Variable to store user input

  // Loop until user enters "yes" (case insensitive)
  do
  {
    std::cout << "Let's play a game! Shall we?\n";
    std::cin >> userinput;
  } while (userinput != "yes" && userinput != "Yes" && userinput != "YES");
  
  // Ask user for the upper limit value
  std::cout << "Give an value up to where the program has to count: ";
  std::cin >> value;
  
  // Call fizzbuzz function with the user-provided value
  fizzbuzz(value);

  return 0;
}
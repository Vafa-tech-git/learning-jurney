#include <iostream>
#include <string>

int main()
{

 // A char variable so it can cycle betwen the letters of the alphabet
  char letter{'a'};
 // The condition to be <= z beacuze if it would've been only < or == z it wouldn't show all the letters
  while (letter <= 'z')
  {

 // The static cast method to convert the letter in her ASCII code
    std::cout << "The letter is " << letter << " and her ASCII code is: " << static_cast<int>(letter) << '\n';
    ++letter;

  }
  

return 0;  
}
#include <iostream>

//The calculate function is making the calculation;
int calculate(int firstn, char op, int secondn)
{
  
  //An switch instruction for every operator
  switch (op)
  {

  case '+':
    return firstn + secondn;
  case '-':
    return firstn - secondn;
  case '*':
    return firstn * secondn;
  case '/':
    if (secondn != 0)
    return firstn / secondn;
      else
        return false;
    //A if statment in case the division is by 0
  case '%':
    if (secondn != 0)
    return firstn / secondn;
      else
        return false;
    //A if statment in case the division is, again, by 0
  default:
    return false;
    //A false return of the function to work with the if in the logic function

  }

}

void logic()
{

  int first, second;
  char op;
  
  //The user input part
  std::cout << "Give the first number: ";
  std::cin >> first;
  std::cout << "Give the operation you want to do: ";
  std::cin >> op;
  std::cout << "Give the second number: ";
  std::cin >> second;

  //A if statment in case somoane gives an invalid opeator
  if ((calculate(first, op, second)))
    std::cout << "The first number " << op << " the second number is: " << calculate(first, op, second);
    else
      std::cout << "The operator isn't valid or the operation isn't possible";
}

int main()
{

  //calling the logic function to put the program altogheter
  logic();

return 0;
}

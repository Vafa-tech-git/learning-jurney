#include <iostream>
#include <functional>

// Gets an integer from the user
int getInteger(){
  std::cout << "Enter an integer: ";
  int x{};
  std::cin >> x;
  
  return x;
}

// Gets a valid operator from the user
char getOperation(){    
  char op{};
  do{
    std::cout << "Enter an operation ('+', '-', '*', '/'): ";
    std::cin >> op;
  } while (op!='+' && op!='-' && op!='*' && op!='/');
  
  return op;
}

// Basic arithmetic functions
int add(int x, int y){
  return x+y;
}

int substract(int x, int y){
  return x-y; 
}

int mulitply(int x, int y){
  return x*y;
}

int divide(int x, int y){
return x/y;
}

// Function pointer wrapper type alias
using ArithmeticFunction = std::function<int (int, int)>;

// Selects the appropriate arithmetic function
ArithmeticFunction getArithmeticFunction(const char& op){
  switch (op){
  case '+' : return &add;
  case '-' : return &substract;
  case '*' : return &mulitply;
  case '/' : return &divide;
  }

  return nullptr;
}

int main(){
  int x{ getInteger() };
  char op{ getOperation() };
  int y{ getInteger() };

  ArithmeticFunction value{ getArithmeticFunction(op) };

  // Run the selected operation if it is valid
  if(value){ 
    std::cout << x << ' ' << op << ' ' << y << " = " << value(x, y) << '\n';
  }

  return 0;
}

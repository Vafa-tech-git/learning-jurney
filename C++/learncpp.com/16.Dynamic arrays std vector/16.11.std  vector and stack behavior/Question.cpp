#include <iostream>
#include <vector>


// Function to print the contents of the stack
void VectorPrint(const std::vector<int>& v){
  if (v.empty()){
    std::cout << "\tStack: empty\n";
  }
  else{
    std::cout << "\t(Stack: ";
    // Print each element in the stack
    for (int i : v){
      std::cout << i << ' ';
    }
    std::cout << ")\n";
  }
}

int main(){

  // Create an empty stack
  std::vector<int> stack{};

  // Print initial stack state
  VectorPrint(stack);

  // Push 1 onto the stack and print
  stack.push_back(1);
  std::cout << "Push " << stack.back();
  VectorPrint(stack);

  // Push 2 onto the stack and print
  stack.push_back(2);
  std::cout << "Push " << stack.back();
  VectorPrint(stack);

  // Push 3 onto the stack and print
  stack.push_back(3);
  std::cout << "Push " << stack.back();
  VectorPrint(stack);

  // Pop the top element and print
  stack.pop_back();
  std::cout << "Pop";
  VectorPrint(stack);

  // Push 4 onto the stack and print
  stack.push_back(4);
  std::cout << "Push " << stack.back();
  VectorPrint(stack);

  // Pop the top element again
  stack.pop_back();
std::cout << "Pop";
VectorPrint(stack);
stack.pop_back();
std::cout << "Pop";
VectorPrint(stack);
stack.pop_back();
std::cout << "Pop";
VectorPrint(stack);

return 0;
}
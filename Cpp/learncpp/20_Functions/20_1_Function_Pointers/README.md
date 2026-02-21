# Function pointers (C++ `std::function`)

A simple arithmetic program demonstrating how to use `std::function` as a wrapper for function pointers.

## Features

- Input two integers from the user.
- Prompt for an arithmetic operation (+, -, *, /).
- Use a function pointer (via `std::function`) to select and execute the operation.

## How it works

1. **Input**: `getInteger()` and `getOperation()` handle user input.
2. **Dispatch**: `getArithmeticFunction()` takes a `char` operator and returns a `std::function<int(int, int)>` pointer to one of the arithmetic functions (`add`, `substract`, `mulitply`, `divide`).
3. **Execution**: The `main` function calls the returned function pointer and prints the result.

## Compilation and usage

Compile using any C++11 (or later) compiler:

```bash
g++ -std=c++11 Question.cpp -o calculator
./calculator
```

# Perfect Square Checker: C++ Namespace Implementation

This program demonstrates how to:
 - Use namespaces to build a structured data container, isolating game variables from global scope.
 - Implement robust input validation and buffer management for integer processing.
 - Manage program state using iterative loops and specific exit signals.
 - Perform linear searches within static arrays to verify data points.

## How it works
1.  The `Data` namespace stores an array of known perfect squares and the current user input, acting as a simple state container.
2.  The program repeatedly prompts the player to enter a single-digit integer or a sentinel value (-1) to terminate the session.
3.  The `UserInput` function performs input sanitization by clearing the `std::cin` buffer if an invalid character is entered, preventing program instability.
4.  The `Found` function utilizes a *range-based loop* to scan the predefined array, returning a boolean status if the input matches a perfect square.
5.  The game concludes when the user enters -1, triggering the final "Bye" message.

## Example Output
```
Enter a single digit integer, or -1 to quit: 4
4 is a perfect square

Enter a single digit integer, or -1 to quit: 3
3 is not a perfect square

Enter a single digit integer, or -1 to quit: -1
Bye
```

## Concepts Covered
 -**Encapsulation**: Using a namespace to protect data while providing controlled access via functions.
 -**Input Sanitization**: Handling invalid integers and clearing the `std::cin` buffer to ensure reliable execution.
 -**State Management**: Using boolean tracking and iterative loops to manage the lifecycle of the user session.
 -**Iterative Search**: Utilizing efficient loops to traverse fixed-size data collections for value verification.
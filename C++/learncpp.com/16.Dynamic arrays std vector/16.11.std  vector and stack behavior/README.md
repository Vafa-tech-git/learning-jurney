# Question: std::vector and Stack Behavior

This program demonstrates how to:
- Use a std::vector to simulate stack behavior (push and pop operations)
- Print the contents of the stack after each operation
- Handle empty stack cases gracefully

## How it works
1. An empty vector is used to represent the stack.
2. The program pushes and pops values, printing the stack after each operation.
3. The stack's state is displayed, including when it is empty.

## Example Output
```
	      Stack: empty
Push 1	(Stack: 1 )
Push 2	(Stack: 1 2 )
Push 3	(Stack: 1 2 3 )
Pop	    (Stack: 1 2 )
Push 4	(Stack: 1 2 4 )
Pop	    (Stack: 1 2 )
Pop	    (Stack: 1 )
Pop	    (Stack: empty)
Pop	    (Stack: empty)
```

## Concepts Covered
- std::vector as a stack
- Push and pop operations
- Output formatting

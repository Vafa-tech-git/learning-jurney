# Find Maximum in a Vector

This program demonstrates how to:
- Use a template function to find the maximum value in a vector of any numeric type
- Handle empty vectors gracefully by returning a default-constructed value
- Test the function with vectors of integers, doubles, and an empty vector

## How it works
1. The `findMax` template function takes a vector and returns the largest value found.
2. If the vector is empty, it returns a default value for the type (e.g., 0 for int, 0.0 for double).
3. The program tests this function with:
   - A vector of integers
   - A vector of doubles
   - An empty vector

## Example Output
```
92
-13
0
```

## Concepts Covered
- Template functions
- Vector traversal
- Handling empty containers
- Output formatting

# Passing `std::vector` to a Function\

This project contains a simple C++ example demonstrating how to pass a `std::vector` to a function and perform safe element access with bounds checking.\

### Key Concepts

1.  **Template Function**: `printElement` is a template function, allowing it to operate on vectors of different types (e.g., `std::vector<int>`, `std::vector<double>`) without needing to be rewritten.\
2.  **Pass by `const` Reference**: The vector is passed as `const std::vector<vectortype>&`.\
    *   The `&` (reference) avoids making a costly copy of the entire vector.\
    *   The `const` ensures the function cannot modify the original vector, making the function safer to use.\
3.  **Bounds Checking**: The `if (index >= vector.size())` check is crucial for preventing out-of-bounds access, which would lead to undefined behavior.\
4.  **`std::size_t` for Indexing**: Using `std::size_t` is the standard and correct way to handle sizes and indices in C++. It's an unsigned type, which prevents negative indices. Note that passing a negative literal like `-1` results in it being converted to a very large positive unsigned number, which is correctly caught by the bounds check.\

## Expected Output\

```
The element has value: 2\
Invalid index\
The element has value: 1.1\
Invalid index\
```
# Sorting Cars with Comparison Operators

## Overview
This example shows how to compare custom objects and use them with the standard library sort algorithm.

## What This Program Does
The `Car` class stores a make and model. The program overloads:

- `operator<` for ordering
- `operator<<` for printing

Then it sorts a vector of cars and prints the result.

## Key Concepts

### 1. Ordering Custom Types
The comparison operator defines how objects should be ranked.

### 2. Sorting with `std::sort`
Once `operator<` is defined, the vector can be sorted without any custom sorting logic.

### 3. Printing Custom Objects
The stream insertion operator allows `Car` values to be displayed naturally with `std::cout`.

## Example Output
```cpp
(Honda, Accord)
(Honda, Civic)
(Toyota, Camry)
(Toyota, Corolla)
```

## Notes
- The comparison is done first by make, then by model when the make is the same.
- This is a common pattern when working with custom data structures.

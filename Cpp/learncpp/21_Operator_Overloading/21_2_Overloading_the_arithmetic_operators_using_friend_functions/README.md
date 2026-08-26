# Overloading the Arithmetic Operators Using Friend Functions

## Overview
This lesson demonstrates how to overload the multiplication operator for a custom `Fraction` class using `friend` functions.

## What This Program Does
The program defines a `Fraction` type that stores a numerator and denominator, reduces fractions to their simplest form, and overloads `operator*` so it can multiply:

- fraction × fraction
- fraction × integer
- integer × fraction

## Key Concepts

### 1. Friend Functions
A `friend` function is a non-member function that has access to the private members of a class. This is useful when we want an operator to work naturally with class objects without making it a member function.

### 2. Operator Overloading
Overloading `operator*` allows expressions like:

```cpp
Fraction f1{ 2, 5 };
Fraction f2{ 3, 8 };
Fraction result{ f1 * f2 };
```

to compile and behave as expected.

### 3. Fraction Reduction
The `Reduce()` function uses `std::gcd()` to simplify the fraction by dividing both the numerator and denominator by their greatest common divisor.

## Example Output
```cpp
2/5
3/8
6/40
4/5
6/8
1/4
0/1
```

The fraction result is reduced whenever it is constructed, so values like `6/40` will be simplified to `3/20` if the reduction logic is applied correctly.

## Notes
- `std::gcd()` requires including `<numeric>`.
- The constructor uses a default denominator of `1` so integer values can be treated as fractions.
- The multiplication operator is overloaded in three forms to support common expressions.

## Summary
This example shows how to make custom arithmetic types work naturally with standard operators, while keeping the class data encapsulated and using `friend` functions for non-member operator implementation.

# Overloading the Comparison Operators

## Overview
This exercise demonstrates how to overload comparison operators for a custom `Fraction` class.

## What This Program Does
The program compares two fractions using:

- `==`
- `!=`
- `<`
- `>`
- `<=`
- `>=`

It then prints whether each comparison is true or false.

## Key Concepts

### 1. Comparison Operators
Operators like `<` and `>` allow objects to be ordered and compared naturally.

### 2. Cross Multiplication
For fractions, comparing `a/b` and `c/d` is done by evaluating:

```cpp
a * d < c * b
```

This avoids converting the values to floating point.

### 3. Friend Functions
The comparison operators are declared as friends so they can access the private members of the `Fraction` class.

## Example
```cpp
3/2 not == 5/8
3/2 != 5/8
3/2 > 5/8
```

The exact output depends on the values being compared, but the operators let the program use normal comparison syntax with custom objects.

## Notes
- Fractions are reduced before comparison so the logic stays consistent.
- Comparison operators are important for sorting, searching, and using custom types in standard library algorithms.

# Overloading the Subscript Operator

## Overview
This exercise demonstrates how to overload `operator[]` so a custom container can behave like an array or map.

## What This Program Does
The `GradeMap` class stores student names and their grades in a `std::vector` of `StudentGrade` objects.

The overloaded subscript operator allows code like this:

```cpp
grades["Joe"] = 'A';
std::cout << grades["Joe"];
```

This makes the class feel similar to a dictionary or lookup table.

## Key Concepts

### 1. Subscript Operator
The `[]` operator is commonly overloaded for container-like classes. It usually returns a reference so assignments and reads behave naturally.

### 2. Searching the Container
The code uses `std::find_if()` to look for an existing student by name.

### 3. Adding a New Entry
If the student is not found, a new `StudentGrade` is added to the vector and a reference to the grade is returned.

## Example
```cpp
GradeMap grades{};
grades["Joe"] = 'A';
grades["Frank"] = 'B';

std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
```

## Notes
- Returning a reference allows assignment to the grade directly.
- Using `std::vector::push_back()` adds a new student record when the name is not already present.
- This pattern is useful for creating simple lookup tables without needing a full map implementation.

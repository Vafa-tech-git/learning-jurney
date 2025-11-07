# Monster Generator

This is a simple C++ program that defines a `Monster` class and uses a `MonsterGenerator` to create and display a monster with randomized attributes.

## Notes

The program has inside jokes and random jokes from Romania for fun, so don't worry about it.

## Description

The program consists of two main parts:

1.  **`Monster` Class**: Represents a monster with a specific type (e.g., dragon, goblin, orc), a name, a roar, and hit points. It includes a method to print the monster's details.
2.  **`MonsterGenerator` Namespace**: A utility that generates a `Monster` object with random characteristics. The type, name, roar, and hit points are all selected randomly from predefined lists or ranges.

The `main` function demonstrates this usage by generating a single random monster and printing its status to the console.

## Dependencies

- `Random.h`: A header-only library for generating random numbers. This file must be in the same directory as `Question_1.cpp`.
Source: Learncpp.com

## Example Output

The output is random and will vary with each execution.

**Example 1:**
```
Nelutu the Troll has 87 hit points and says HAU.
```

**Example 2:**
```
Gica the Skeleton is dead
```
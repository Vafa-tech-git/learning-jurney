# Overloading the I/O Operators (Exercise)

This example implements a simple `Fraction` class with overloaded
input/output operators and multiplication operators.

## Files
- `Question.cpp` — Fraction class, stream operators, and a small `main()`.

## Build
Compile with a C++17-compatible compiler:

```bash
g++ -std=c++17 Question.cpp -o Question
```

## Run
Example interaction (input is provided as `numerator/denominator` lines):

```bash
# run and type input interactively
./Question
Enter fraction 1: 2/3
Enter fraction 2: 3/8
2/3 * 3/8 is 1/4

# or pipe input
printf "2/3\n3/8\n" | ./Question
```

## Notes
- The input operator expects the format `N/D` and will fail if `D` is 0.
- Fractions are reduced to lowest terms automatically.

# Advanced FizzBuzz with Multiple Divisors

This program demonstrates how to:
- Use vectors to manage multiple divisors and their corresponding output words
- Loop through a range of numbers and print special words for numbers divisible by any of the divisors
- Print the number itself if it is not divisible by any listed divisor
- Ensure data consistency with assertions

## How it works
1. Two vectors are defined: one for divisors and one for their corresponding words.
2. The program loops from 1 to 150.
3. For each number, it checks divisibility by each divisor:
   - If divisible, it prints the corresponding word (can print multiple words for numbers divisible by several divisors).
   - If not divisible by any, it prints the number itself.
4. Each result is printed on a new line.

## Example Output (partial)
```
1
2
fizz
4
buzz
fizz
pop
8
fizz
buzz
11
fizz
13
pop
fizzbuzz
...
```

## Concepts Covered
- Vectors and string_view
- Nested loops
- Conditional output
- Data validation with assertions

# 20_6_Introduction_to_lambdas - Question_1

## Overview
This exercise uses a lambda comparator to find the student with the highest score in a fixed array.

## Files
- `question.cpp` - source file showing `std::max_element` with a lambda comparator.
- `question` - compiled executable binary.

## Build
```bash
cd Cpp/learncpp/20_Functions/20_6_Introduction_to_lambdas/Question_1
g++ question.cpp -o question
```

## Run
```bash
./question
```

## Notes
- The lambda compares two `Student` objects by their `points` field.
- The program prints the name of the student with the highest score.

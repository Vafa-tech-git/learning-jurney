# 20_6_Introduction_to_lambdas - question_2

## Overview
This exercise sorts a list of seasons by average temperature using a lambda comparator.

## Files
- `question.cpp` - source file showing `std::sort` with a lambda comparator.
- `question` - compiled executable binary.

## Build
```bash
cd Cpp/learncpp/20_Functions/20_6_Introduction_to_lambdas/question_2
g++ question.cpp -o question
```

## Run
```bash
./question
```

## Notes
- The lambda orders `Season` objects by `averageTemperature`.
- The program prints season names from coldest to warmest.

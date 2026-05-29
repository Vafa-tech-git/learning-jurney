# 20_7_Lambda_captures

## Overview
This exercise demonstrates lambda captures and user interaction with a guessing game.
The program generates a list of squared values multiplied by a random integer, then asks the player to guess the generated numbers.

## Files
- `question.cpp` - main source file for the exercise.
- `Random.h` - header-only random number helper used to generate the multiplier.
- `question` - compiled executable binary.

## Build
```bash
cd Cpp/learncpp/20_Functions/20_7_Lambda_captures
g++ squestion.cpp -o question
```

## Run
```bash
./question
```

## Notes
- The program prompts for a starting number and how many values to generate.
- It then multiplies each square by a random integer between 2 and 4.
- The player guesses values until all numbers are found or a wrong guess ends the game.

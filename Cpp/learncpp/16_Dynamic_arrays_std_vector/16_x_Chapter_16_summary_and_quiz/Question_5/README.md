# C++ Man: Modern Hangman implementation

This program demonstrates how to:
 - Use classes and namespaces to build a structured game engine
 - Manage game state using vectors and boolean tracking
 - Implement robust input validation and buffer management
 - Utilize modern random number generation for dynamic gameplay

## How it works
1. The `Session` class picks a random word and tracks which letters the player has guessed correctly and incorrectly.
2. The program displays the word with underscores for hidden letters and a "plus-based" bar (++++++) representing remaining lives.
3. Players enter letters; correct guesses reveal parts of the word, while incorrect guesses reduce the turn count.
4. The game concludes when the word is fully revealed (Win) or the turns run out (Loss), followed by a final reveal of the word.

## Example Output
```
welcome to C++ man (a variant of hangman)
To win: guess the word. To lose: run out of pluses.

The word: _______   Wrong guesses: ++++++

Enter your next letter: a
The word: a______   Wrong guesses: ++++++

Enter your next letter: x
The word: a______   Wrong guesses: +++++x
```

## Concepts Covered
 - Encapsulation: Using a class to protect game data while providing controlled access via getters.
 - Modern Randomization: Seeding std::mt19937 with std::chrono for high-quality randomness.
 - Memory Optimization: Passing large objects by const reference to avoid expensive copying.
 - Input Sanitization: Handling invalid characters and clearing the std::cin buffer.
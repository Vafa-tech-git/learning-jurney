#include <iostream>
#include <random>

// The random number generator function
int prng()
{   
// Random device variable beacuse we don't need a long period.
    std::random_device rd;

// A coustom seed variable to use the random device variable.
    std::seed_seq seed{rd()};

// Initializing the Mersenne Twister random number generator with the custom seed.
    std::mt19937 iprng{seed};

// A uniform int distribution variable to limit the range of the prng.
    std::uniform_int_distribution fprng{1, 100};

// returning the limit variable with the prng argument.
return fprng(iprng);
}

int main()
{
// A char variable in order to make the user play again option as memory inexpensive as possible.
    char pagain;

// A do while instruction to make the game replayable
    do
    {
        std::cout << "Let's play a game! I'm thinking of an number beetwen 1 to 100. You have 7 tries\n";

// You can't use functions as conditions so we put the function return value in an variable.
        int guessresult{prng()}; 

// Initialize guess variable outside of the for loop to save memory.
        int guess{0};

// For loop to limit the player to only 7 tries.
        for (int guesscount{1}; (guesscount<=7) ; guesscount++)
        {
            std::cout << "Guess #" << guesscount << ": \n";
            std::cin >> guess;

// If to decide either the user guess is higher than the number it needs to guess or lower.
            if (guess > guessresult)
            {
                std::cout << "Your guess is too high\n";
            }
                else
                    std::cout << "Your guess is too low\n";
        }

// Another if to deicde if the player won or lost.
        if (guess == guessresult)
        {
            std::cout << "Correct! You won!\n";
        }
            else
            {
                std::cout << "Sorry, you lose. The correct number was " << guessresult << ".\n";
            }

// Ask the player if he wants to play again or not.
        std::cout << "Would you like to play again? (Y/N)\n";
        std::cin >> pagain;
    }
    while (pagain!='N');

// If the player says he dosen't wants to play again thank him.
    if (pagain == 'N')
    {
        std::cout << "Thank you for playing.";
    }

return 0;
}
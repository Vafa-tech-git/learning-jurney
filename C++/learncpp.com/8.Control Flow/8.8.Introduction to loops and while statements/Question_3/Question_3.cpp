#include <iostream>

int main()
{
    int endlcontrol{5}; // Controls the number of lines and starting number for each line

    while (endlcontrol >= 1) // Outer loop: runs from 5 down to 1
    {
        int number{ endlcontrol }; // Initialize number to current endlcontrol value
        while (number >= 1) // Inner loop: prints numbers from 'number' down to 1
        {
            std::cout << number--; // Print current number, then decrement
        }
        std::cout << '\n'; // Print newline after each row
        --endlcontrol; // Decrement endlcontrol for next row
    }

    return 0;
}
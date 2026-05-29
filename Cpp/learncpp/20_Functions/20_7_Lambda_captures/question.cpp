#include <iostream>
#include </home/vali/Desktop/Projects/learning_jurney/Cpp/learncpp/20_Functions/20_7_Lambda_captures/Random.h>
#include <vector>
#include <algorithm>
#include <cmath>

// Global settings used for random multiplier bounds.
namespace Settings{
  const int minimum_rinteger{2};
  const int maximum_rinteger{4};
}

void setup(int& whereinp, int& manyinp, std::vector<int>& guessvalues){
  // Ask the user where the first value should start.
  std::cout << "Start where? ";
  std::cin >> whereinp;

  // Ask how many numbers should be generated.
  std::cout << "How many? ";
  std::cin >> manyinp;

  // Choose a random multiplier between the configured limits.
  const int rinteger{Random::get(Settings::minimum_rinteger, Settings::maximum_rinteger)};

  // Generate the requested number of values and store them.
  for (int i{0}; i < manyinp; i++){
    guessvalues.push_back((whereinp * whereinp) * rinteger);
    whereinp++;
  }

  std::cout << "I generated " << manyinp << " square numbers. Do you know what each number is after multiplying it by " << rinteger << "?\n";
}

int main(){

  int whereinp, manyinp;
  std::vector<int> guessvalues{};

  setup(whereinp, manyinp, guessvalues);

  // gameplay logic begins here.
  int guess;

  // The nearest element is determined by which value is closest to the guessed value.
  auto nearest = std::min_element(guessvalues.begin(), guessvalues.end(), [guess](int a, int b){
    return std::abs(a - guess) < std::abs(b - guess);
  });

  while (true){
    std::cin >> guess;

    // Look for an exact match among the generated values.
    auto found(std::find(guessvalues.begin(), guessvalues.end(), guess));

    if (found != guessvalues.end()){
      // Correct guess: remove it from the list and update remaining count.
      guessvalues.erase(found);
      manyinp--;
      if (manyinp == 0){
        std::cout << "Nice! You found all numbers, good job!";
        break;
      }
      std::cout << "Nice! " << manyinp << " number(s) left.\n";
    }
    else if (nearest != guessvalues.end()){
      // Incorrect guess: provide the closest value and end the game.
      std::cout << guess << " is wrong! Try " << *nearest << " next time.";
      break;
    }
  }

return 0;
}
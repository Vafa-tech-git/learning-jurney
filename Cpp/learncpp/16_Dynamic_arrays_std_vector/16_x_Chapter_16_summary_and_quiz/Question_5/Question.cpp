#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string_view>
#include <limits>
#include <iterator>
#include <cassert>

// Namespaces organize settings and data.
namespace Settings{
  short turns{6};
}

namespace WordList{
// std::vector of std::string_view provides memory-efficient string access.
  const std::vector<std::string_view> words{"mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage", "alo"};
}

std::size_t Generator(){

  std::random_device rd{};

// Use static_cast for seed types soo the type match.
  std::seed_seq ss{static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
  static std::mt19937 generator{ss};
  std::uniform_int_distribution<size_t> limits(0, WordList::words.size() - 1);

return limits(generator);
}

// Clears the buffer, if the user enters an invalid input it resets cin fail bit.
void InputValidation(){
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (!std::cin) {
    std::cin.clear();
  }
}

class Session;
char UserInput(const Session& session);

class Session{

private:

// Members represent the game state.

  const std::string m_word{WordList::words[Generator()]};
  const short m_word_length{static_cast<short>(m_word.length())};

  std::vector<bool> m_guess = std::vector<bool>(m_word_length, false);

  std::vector<char> m_letters_guessed{};
  std::vector<char> m_incorrect_letters{};

  friend char UserInput(const Session& session);

public:

// Core game logic uses loops to update state.
  void Input(char& input){
    m_letters_guessed.push_back(input);
    bool found{false};

// Indexed loop compares player input to the word.
    for (int i{0}; i < m_word.length(); i++){
      char wordchar = m_word[i];  

      if (input == wordchar){
        m_guess[i] = true;
        found = true;
      }
    }

// Conditional state updates.
    if (found){
      Settings::turns += 1;
    }
    else{
      m_incorrect_letters.push_back(input);
    }

  }

// Getters provide read-only access to internal vectors.
  const std::string& wordgetter() const { return m_word; }
  auto& guessgetter() const { return m_guess; }
  auto& incorectlettersgetter() const { return m_incorrect_letters; }
};

char UserInput(const Session& session){
  char input{';'};
  const std::vector<char> alphabet{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  bool found{false};

  do{
    std::cout << "Enter your next letter: ";
    std::cin >> input;

// Range-based loop for validation.
    for (const auto& i : alphabet){
      if (input == i){ 
        found = true;
        break;
      }
    }

    if (!found){
      std::cout << "That wasn't a valid input. Try again!\n";
    }

// Checking against already guessed letters to ensure logic consistency.
    for (const auto& i : session.m_letters_guessed){
      if (input == i){
        std::cout << "Invalid letter. Already guessed\n";
        found = false;
        break;
      }
    }

    InputValidation();

  } while (!found);

return input;
}

// Handles output formatting based on game state.
void Draw(const Session& session, bool reveal = false){

  std::cout << "The word: ";

  const auto& word = session.wordgetter();
  const auto& guess = session.guessgetter();
  const auto& incorrectletters = session.incorectlettersgetter();

// Conditional output based on game rules.
  for (std::size_t i = 0; i < word.size(); ++i){
    if (guess[i] || reveal){
      std::cout << word[i];
    }
    else{
      std::cout << "_";
    }
  }

  std::cout << "   \tWrong guesses: ";

  for (int i{0}; i <= Settings::turns; i++){
    std::cout << '+';
  }

  for (const auto& element : incorrectletters){
    std::cout << element;
  }

  std::cout << "\n\n";

}

// Checks for a win state by iterating through booleans.
void WinCheck(const Session& session, bool& win){

  const auto& guess = session.guessgetter();

  for (const auto& element : guess){
    if (element){
      win = true;
    } 
    else{

// Reset if any part of the word is missing.
      win = false;
      break;
    }
  }

}

int main(){

  std::cout << "welcome to C++ man (a variant of hangman)\n";
  std::cout << "To win: guess the word. To lose: run out of pluses.\n\n";

  Session session;
  bool win(false);

// Main game loop manages turns.
  while (Settings::turns--){

    Draw(session);        
    char guess = UserInput(session);
    session.Input(guess);
    WinCheck(session, win);

    if (win){
      std::cout << "Congraseleisen, You won!\n";
      break;
    }
    else if (Settings::turns == 0){
      std::cout << '\n';
      std::cout << "You lost!\n";
    }

  }

// Final reveal using conditional formatting.
  std::cout << '\n';
  Draw(session, true);

// Wait for user input before the console close.
  std::cout << "Press enter to exit...";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();

return 0;
}
#include "../Question_3/Question.cpp"
#include <iostream>

// Configuration settings for the Blackjack game
namespace Settings {
  int bust_score{21};    // Maximum score before a player busts
  int dealer_stop{17};   // Score at which the dealer must stop hitting
}

// Represents a participant in the game
struct Player {
  int score{}; // Current total score of the player or dealer
};

// Evaluates the final scores and determines the winner
void Blackjack(const Player& player, const Player& dealer) {
  if (dealer.score > Settings::bust_score) {
    std::cout << "The dealer went bust!\n You win!";
  }
  else if (player.score > Settings::bust_score) {
    std::cout << "You went bust!\n You lose!";
  }
  else if (dealer.score >= player.score) {
    std::cout << "You lose!";
  }
  else {
    std::cout << "You win!";
  }
}

// Handles the dealer's turn logic: hits until reaching the dealer_stop score
void DealerTurn(Player& dealer, Deck& deck, const Player& player) {
  while (dealer.score < Settings::dealer_stop && player.score < Settings::bust_score) {
    deck.Shuffle();
    dealer.score += deck.DealCard().CardValue();
    std::cout << "The dealer flips a " << deck.DealCard() << ". They now have: " << dealer.score << '\n';
  }
}

// Prompt the player for their move
bool PlayerInput() {
  char input;
  while (true) {
    std::cout << "(h) to hit, or (s) to stand: ";
    std::cin >> input;

    switch (input) {
    case 'h': return true;
    case 's': return false;
    default: continue; // Repeat if input is invalid
    }
  }
}

// Handles the player's turn logic: allows hitting until bust or stand
void PlayerTurn(Player& player, Deck& deck) {
  while (player.score < Settings::bust_score && PlayerInput()) {
    player.score += deck.DealCard().CardValue();
    std::cout << "You were dealt " << deck.DealCard() << ". You now have: " << player.score << '\n';
  }
}

int main() {
  Deck deck;
  deck.Shuffle();

  // Initial deal: dealer gets one card, player gets two
  Player dealer{deck.DealCard().CardValue()};
  Player player{deck.DealCard().CardValue() + deck.DealCard().CardValue()};

  std::cout << "The dealer is showing: " << dealer.score << '\n';
  std::cout << "You have score: " << player.score << '\n';

  // Execute game turns
  PlayerTurn(player, deck);
  DealerTurn(dealer, deck, player);

  // Determine final outcome
  Blackjack(player, dealer);

  return 0;
}
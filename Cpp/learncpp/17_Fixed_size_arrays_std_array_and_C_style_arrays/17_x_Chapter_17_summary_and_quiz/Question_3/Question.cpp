#include <iostream>
#include <string_view>
#include <array>
#include "Random.h"
#include <algorithm>
#include <cassert>

// Represents a single playing card
struct Card{

  enum Rank{
    rank_ace,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    max_rank
  };

  enum Suit{
    suit_club,
    suit_diamond,
    suit_heart,
    suit_spade,
    max_suit
  };

  Rank rank{};
  Suit suit{};

  // Overload the << operator to print the card in a readable format (e.g., "AS", "2H")
  friend std::ostream& operator<<(std::ostream& out, const Card& card){
    static constexpr std::array ranks { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
    static constexpr std::array suits { 'C', 'D', 'H', 'S' };
    
    out << ranks[card.rank] << suits[card.suit];

  return out;
  };

  static constexpr std::array<Rank, max_rank> all_ranks{rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king};
  static constexpr std::array<Suit, max_suit> all_suits{suit_club, suit_diamond, suit_heart, suit_spade};

  // Returns the value of the card in a game (e.g., Blackjack)
  int CardValue() const{

      static constexpr std::array rankValues { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

  return rankValues[rank];
  }

};

// Represents a deck of 52 playing cards
class Deck{

  private:

    std::array<Card, 52> m_cards{};
    std::size_t m_next_card{0}; // Index of the next card to be dealt

  public:

  // Constructor: Initializes the deck with 52 unique cards
  Deck(){

    int count{0};

    for(const auto& suit : Card::all_suits){
      for(const auto& rank : Card::all_ranks){
        m_cards[count++] = Card{rank, suit};
      }
    }
  };

  // Shuffles the deck using a random number generator
  void Shuffle(){
    std::shuffle(m_cards.begin(), m_cards.end(), Random::generate());
    m_next_card = 0; // Reset the deal index after shuffling
  }

  // Deals the next card from the deck
  Card DealCard(){
    assert(m_next_card < 52); // Ensure there are cards left to deal

    return m_cards[m_next_card++];
  }

};
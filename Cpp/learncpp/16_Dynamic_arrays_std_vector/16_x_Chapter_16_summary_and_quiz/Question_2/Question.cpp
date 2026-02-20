#include <iostream>
#include <vector>
#include <cassert>
#include <string_view>
#include <string>

// Inventory namespace holds item types and their counts
namespace Inventory{

  enum Items{
    health_potions,
    torches,
    arrows,
    max_items
  };

  const std::vector item_count {1, 5, 10};

}


// Returns the name of the item as a string_view
std::string_view ItemsOut(Inventory::Items item){
  switch (item){
    case Inventory::health_potions : return "Health Potion";
    case Inventory::torches : return "Torch";
    case Inventory::arrows : return "Arrow";
    default : return "N/N";
  }
}


// Prints the total number of all items
void TotalItems(){
  int total_items{0};
  for (const auto& element : Inventory::item_count){
    total_items += element;
  }
  std::cout << "You have " << total_items << " in total.";
}


// Prints each item with correct pluralization
void WordsPluralization(){
  for (int i{0}; i < Inventory::max_items; i++){
    const std::string_view word{ItemsOut( static_cast<Inventory::Items>(i) )};
    const std::string_view last2digits = word.substr(word.length()-2, 2);
    std::cout << "You have " << Inventory::item_count[i] << ' ';

    // Pluralization rules
    if((word.back() == 'o' || last2digits == "ch" || last2digits == "sh" || word.back() == 'x' || last2digits == "ss" || word.back() == 's' || word.back() == 'z') && Inventory::item_count[i] > 1){
      std::cout << word << "es\n";
    }
    else if(Inventory::item_count[i] > 1){
      std::cout << word << "s\n";
    }
    else{
      std::cout << word << '\n';
    }
  }
}


int main(){
  // Check that the item count matches the enum
  assert(Inventory::max_items==Inventory::item_count.size());

  WordsPluralization();

  TotalItems();
  return 0;
}
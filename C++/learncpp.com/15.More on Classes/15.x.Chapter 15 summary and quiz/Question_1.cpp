#include <iostream>
#include <string>
#include "Random.h"


class Monster{

public:
// Enum to define the different types of monsters.
enum Type{
  dragon,
  goblin,
  ogre,
  orc,
  skeleton,
  troll,
  vampire,
  zombie,
  maxMonsterTypes, // A sentinel value to count the number of monster types.
};

private:
// Private member variables for the Monster class.
Type m_type{};
std::string m_name{"???"};
std::string m_roar{"???"};
int m_hit_points{};

public:

// Constructor to initialize a Monster object.
Monster(Type type, const std::string& name, const std::string& roar, const int& hit_points) : m_type{type}, m_name{name}, m_roar{roar}, m_hit_points{hit_points}{
}

// Converts a Monster::Type enum to its string representation.
std::string get_type_string(Type monstertype) const {

  switch (monstertype){
    case dragon : return  "Dragon";
    case goblin : return "Gobiln";
    case ogre : return "Ogre";
    case skeleton : return "Skeleton";
    case troll : return "Troll";
    case vampire : return "Vampire";
    case zombie : return "Zombie";
    case orc : return "Orc";
    default : return "???";
  };
}

  // Prints the monster's details to the console.
  void print() const {
    if ( m_hit_points > 0)
      std::cout << m_name << " the " << get_type_string(m_type) << " has " << m_hit_points << " hit points and says " << m_roar << ".\n";
        else
          std::cout << m_name << " the " << get_type_string(m_type) << " is dead\n";
    }

};

// A namespace for functions that generate random monsters.
namespace MonsterGenerator{

  // Returns a random name based on an integer input.
  std::string name_choser(const int& name_number){
    switch (name_number){
      case 1 : return "Nelutu";
      case 2 : return "Dani";
      case 3 : return "Ionut";
      case 4 : return "Maria";
      case 5 : return "Gica";
      case 6 : return "Edi";
      case 7 : return "Nicu";
      case 8 : return "Lucretia";
      default : return "???";
    }
  }

  // Returns a random roar based on an integer input.
  std::string roar_choser(const int& roar_number){
    switch (roar_number){
      case 1 : return "HAU";
      case 2 : return "pE Ele";
      case 3 : return "Shaw";
      case 4 : return "inca una si ma duc";
      case 5 : return "alo pinguini";
      case 6 : return "am prins pedofilu";
      case 7 : return "feriti-va copilu Romeo pedofilu";
      case 8 : return "ai kendama fake";
    }
  }

  // Generates a Monster with random attributes.
  Monster generate(){
    // The monster type is chosen from 1 up to maxMonsterTypes - 1 to avoid the sentinel value.
    return Monster {static_cast<Monster::Type>(Random::get(1, Monster::maxMonsterTypes-1)), name_choser(Random::get(1, 8)), roar_choser(Random::get(1, 8)), Random::get(-100, 100)};
  }

}


int main()
{
    // Generate a random monster.
    Monster m{ MonsterGenerator::generate() };
    // Print the monster's details.
    m.print();

return 0;
}

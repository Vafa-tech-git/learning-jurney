#include <iostream>
#include <string>
#include <string_view>

// Defines a structure to represent a monster
struct Monster{

// Defines an enumeration for the type of monster
  enum monstertype{

    ogre,
    dragon,
    orc,
    giantspider,
    slime
  };
// This variable will hold the type of the monster (e.g., ogre, dragon)
  monstertype type{};

  std::string monsteruser;
  int health{0};

};

// Function to get the name of the monster type as a string
constexpr std::string_view getmonstertype( Monster::monstertype mtypename ){

  switch (mtypename){
    case Monster::ogre: return "Ogre";
    case Monster::dragon: return "Dragon";
    case Monster::orc: return "Orc";
    case Monster::giantspider: return "Giant Spider";
    case Monster::slime: return "Slime";
  }

return "???";
}

// Function to print the details of a monster
void printmonster(const Monster& monster){

std::cout << "This "<< getmonstertype(monster.type) << " is named " << monster.monsteruser << " and has " << monster.health << " health.\n";

}


int main(){

// Creates two monster objects
  Monster useogre { Monster::ogre, "Torg", 145 };
  Monster useslime { Monster::slime, "Blurp", 23 };

// Prints the details of the two monsters
  printmonster(useogre);
  printmonster(useslime);

return 0;
}

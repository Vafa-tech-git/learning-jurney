  #include <iostream>
  #include <array>
  #include <string_view>
  #include <iterator>
  #include <string>
  #include <vector>
  #include <random>
  #include <chrono>
  #include <limits>
  #include <cctype>
  #include <algorithm>

  using namespace std::literals::string_view_literals;

  // Generates a random amount of starting gold between 80 and 120
  int Generator(){

    std::random_device rd{};

    std::seed_seq seed{static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    static std::mt19937 generator{seed};
    std::uniform_int_distribution<int> limits(80, 120);

  return limits(generator);
  }

  // Definitions for potion types, costs, and names
  namespace Potion{

    enum Type{
      healing_potion,
      mana_potion,
      speed_potion,
      invisibility_potion,
      max_potions
    };

    constexpr std::array<int, 4> cost {20, 30, 12, 50};
    constexpr std::array<std::string_view, 4> name {"healing"sv, "mana"sv, "speed"sv, "invisibility"sv};

  }
  
  // Manages the player's session, including inventory and gold
  class Session{

    private:
      std::string m_name{"???"};
      std::vector<Potion::Type> m_inventory{};
      int m_gold{Generator()};

      // Checks if there are extra characters in the input buffer
      bool hasExtraneousInput(){
        return std::cin.peek() != '\n';
      }

      // Clears the input buffer to prevent read errors
      void BufferClear(){
        if(!std::cin)
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }

      // Converts a numeric character to its integer value
      int charNumToInt(char c){
      return c - '0';
      }

      // Displays the shop menu if the previous input was valid
      void PurchaseSystemDraw(const bool& valid){
        if (valid){
          std::cout << "\nHere is our selection for today:\n";
          for (std::size_t i{0}; i < Potion::Type::max_potions; i++){
            std::cout << i << ") " << Potion::name[i] << " costs " << Potion::cost[i] << '\n';
          }

          std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";

        }
      }

      // Validates user input for purchasing potions
      void ValidationConditioning(const int& numeric_input, const char& input, bool& valid){

        if(numeric_input > Potion::max_potions-1 || numeric_input < 0){
          valid = false;
        }

        if(isalpha(input)){
          valid = false;
        }

      }

      // Updates inventory and gold after a successful purchase
      void InventorySystemDraw(const int& numeric_input){

        std::cout << "You purchased a potion of " << Potion::name[numeric_input] << ".";

        m_inventory.push_back(static_cast<Potion::Type>(numeric_input));
        m_gold -= Potion::cost[static_cast<std::size_t>(numeric_input)];

        std::cout << "  You have " << m_gold << " gold left.\n";
      }

    public:
      // Prompts the user for their name
      void UserName(){

        std::cout << "Enter your name: "; 
        std::getline(std::cin >> std::ws, m_name);
        std::cout << "Hello, " << m_name << ", you have " << m_gold << " gold.";

      }

      // Main loop for the purchasing system
      void PurchaseSystem(){

        bool valid{true};
        char input{};

        do{

          PurchaseSystemDraw(valid);

          valid = true;

          std::cin >> input;
          if(hasExtraneousInput()){
            std::cout << "No extra input allowed.\n";
          }

          BufferClear();

          if(input == 'q'){
            break;
          }

          int numeric_input{charNumToInt(input)};

          ValidationConditioning(numeric_input, input, valid);


          if(!valid){
            std::cout << "That is an invalid input.  Try again: ";
          }
          else if(m_gold >= Potion::cost[numeric_input]){
            InventorySystemDraw(numeric_input);
          }
          else{
            std::cout << "You can not afford that.\n";
          }

        } while (true);

      }

      // Prints the final inventory summary
      void InventoryPrint(){

        std::cout << "\nYour inventory contains:\n";

        for(int i{0}; i < Potion::max_potions; i++){

          auto quantity = count(m_inventory.begin(), m_inventory.end(), i);

          if (quantity > 0){
            std::cout << quantity << "x potion of " << Potion::name[i] << '\n';
          }
        }

        std::cout << "You escaped with " << m_gold << " gold remaining.";

      }

  };

  // Main shop interface function
  void shop(Session& session){

    std::cout << "Welcome to Roscoe's potion emporium!\n";
    session.UserName();
    std::cout << "\n\n";

    session.PurchaseSystem();

    session.InventoryPrint();

    std::cout << "\n\n";
    std::cout << "Tanks for shopping at Roscoe's potion emporium!";

  }

int main(){

    Session session;

    shop(session);

return 0;
}
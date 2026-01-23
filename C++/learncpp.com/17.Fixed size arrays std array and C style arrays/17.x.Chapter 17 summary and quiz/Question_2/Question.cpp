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

  using namespace std::literals::string_view_literals;

  int Generator(){

    std::random_device rd{};

    std::seed_seq seed{static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    static std::mt19937 generator{seed};
    std::uniform_int_distribution<int> limits(80, 120);

  return limits(generator);
  }

  namespace Potion{

    enum Type{
      healing_potion,
      mana_potion,
      speed_potion,
      invisibility_potion,
      max_potions
    };

    std::array<int, 4> cost {20, 30, 12, 50};
    constexpr std::array<std::string_view, 4> name {"healing"sv, "mana"sv, "speed"sv, "invisibility"sv};

  }

  /*TODO Add the ability to purchase potions, handling invalid input (treat any extraneous input as a failure).
  Print the player’s inventory after they leave. The program should be complete after this step.

  Make sure you test for the following cases:

  User enters an invalid potion number (e.g. ‘d’)
  User enters a valid potion number but with extraneous input (e.g. 2d, 25)*/

  /*Welcome to Roscoe's potion emporium!
  Enter your name: Alex
  Hello, Alex, you have 85 gold.

  Here is our selection for today:
  0) healing costs 20
  1) mana costs 30
  2) speed costs 12
  3) invisibility costs 50
  Enter the number of the potion you'd like to buy, or 'q' to quit: a
  That is an invalid input.  Try again: 3
  You purchased a potion of invisibility.  You have 35 gold left.*/

  class Session{

    private:
      std::string m_name{"???"};
      std::vector<Potion::Type> m_inventory{};
      int m_gold{Generator()};

      void InputValidation(){
        if(!std::cin)
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }

      int charNumToInt(char c){
      return c - '0';
      }

      void PurchaseSystemDraw(const bool& valid){
        if (valid){
          std::cout << "\nHere is our selection for today:\n";
          for (std::size_t i{0}; i < Potion::Type::max_potions; i++){
            std::cout << i << ") " << Potion::name[i] << " costs " << Potion::cost[i] << '\n';
          }

          std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";

        }
      }

      void ValidationConditioning(const int& numeric_input, const char& input, bool& valid){

        if(numeric_input > Potion::max_potions-1 || numeric_input < 0){
          valid = false;
        }

        if(isalpha(input)){
          valid = false;
        }

      }

    public:
      void UserName(){

        std::cout << "Enter your name: "; 
        std::getline(std::cin >> std::ws, m_name);
        std::cout << "Hello, " << m_name << ", you have " << m_gold << " gold.";

      }

      void PurchaseSystem(){

        bool valid{true};
        char input{};

        do{
          
          if (m_gold < Potion::cost[3]){
            break;
          }

          PurchaseSystemDraw(valid);

          valid = true;

          std::cin >> input;
          InputValidation();

          if(input == 'q'){
            break;
          }

          int numeric_input{charNumToInt(input)};

          ValidationConditioning(numeric_input, input, valid);


          if(!valid){
            std::cout << "That is an invalid input.  Try again: ";
          }
          else if(m_gold >= Potion::cost[numeric_input]){
            m_inventory.push_back(static_cast<Potion::Type>(numeric_input));
            m_gold -= Potion::cost[static_cast<std::size_t>(numeric_input)];
          }

          std::cerr << "\n \tTest Gold" << m_gold;

        } while (true);

      }

  };

  void shop(Session& session){

    std::cout << "Welcome to Roscoe's potion emporium!\n";
    session.UserName();
    std::cout << "\n\n";

    session.PurchaseSystem();

    std::cout << '\n';
    std::cout << "Tanks for shopping at Roscoe's potion emporium!";

  }

  int main(){

    Session session;

    shop(session);

  return 0;

  }
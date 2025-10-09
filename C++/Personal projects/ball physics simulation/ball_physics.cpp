#include <iostream>
namespace generalmath
{

  constexpr int g{10};

}

  // function for tower height
  float towerheightget()
  {
    
    float towerheight;
    std::cout << "What height do you want your tower to be?\n";
    std::cin >> towerheight;
    
  return towerheight;
  }

  // function for ball physics calculations  
  void ballcalc(float towerheight)
  {
  
  // initializate the amount of seconds you want to know the distance of the ball from the ground
    int seconds;
  
  // the distance the ball has fallen in meters and the distance the ball has from the ground. 
    float distance, distance_from_ground;
    std::cout << "How many seconds do you want to see the height of the ball?\n";
    std::cin >> seconds;
      distance_from_ground = towerheight;
  // loop to show the distance from the ground every second
    for ( int t{1}; ( t <= seconds ); ++t)
    {
      
      distance = ( 0.5f * generalmath::g * t * t );
      distance_from_ground = distance_from_ground - distance;
      
  // if statment to show if the ball has been touching the ground
      if ( (distance_from_ground >= 0) )
          std::cout << "The distance after " << t << " is: " << distance_from_ground << '\n';
            else
                {
                std::cout << "The ball has tocuhed the ground";
                break;
                }
    }

  }

int main()
{

    // program run
  ballcalc(towerheightget());

}

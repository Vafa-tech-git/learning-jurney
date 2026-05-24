#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <functional>

// A structure that stores a season name and its average temperature.
struct Season
{
  std::string_view name{};
  double averageTemperature{};
};

int main()
{
  // Create an array of four seasons with average temperatures.
  std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 },
      { "Winter", 263.0 } }
  };

  // Sort seasons by average temperature using a lambda comparator.
  // The comparator returns true when the first season is colder than the second.
  std::sort(seasons.begin(), seasons.end(), [] (const auto& a, const auto& b){
    return a.averageTemperature < b.averageTemperature;
  });

  // Print the season names in sorted order.
  for (const auto& season : seasons)
  {
    std::cout << season.name << '\n';
  }

  return 0;
}


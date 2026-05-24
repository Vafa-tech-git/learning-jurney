#include <string>
#include <iostream>
#include <functional>
#include <array>

// A simple structure representing a student and their score.
struct Student{

  std::string name;
  int points;

};

int main(){
  // An array of 8 students with their corresponding point totals.
  std::array<Student, 8> arr{
    { { "Albert", 3 },
      { "Ben", 5 },
      { "Christine", 2 },
      { "Dan", 8 }, // Dan has the most points (8).
      { "Enchilada", 4 },
      { "Francis", 1 },
      { "Greg", 3 },
      { "Hagrid", 5 } }
  };

  // Use std::max_element with a lambda comparator to find the student with the highest points.
  // The comparator returns true when the first student has fewer points than the second.
  const auto best{std::max_element(arr.begin(), arr.end(), [] (const auto& a, const auto& b){
    return (a.points < b.points);
  })};

  // Print the name of the best student.
  std::cout << best->name;

  return 0;
}


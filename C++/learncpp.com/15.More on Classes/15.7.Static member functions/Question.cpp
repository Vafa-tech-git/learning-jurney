#include <chrono>
#include <random>
#include <iostream>


class Random
{
private:
// Create and return a seeded std::mt19937 engine.
// This function is called only to initialize the static engine below.
  static std::mt19937 generate()
  {
    std::random_device rd{};

// Build a seed_seq from a high-resolution clock plus several random_device values
// to increase entropy for the engine seed.
    std::seed_seq ss{
      static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()), rd(), rd(), rd(), rd(), rd(), rd(), rd() };

        return std::mt19937{ ss }; // return a seeded mt19937 engine
    }

// A single shared mt19937 engine for the class.
// It is initialized once by calling generate().
  static inline std::mt19937 mt{ generate() };

public:
// Generate a random integer in the inclusive range [min, max].
// Uses the shared engine and a std::uniform_int_distribution.
    static int get(int min, int max)
    {
        return std::uniform_int_distribution{min, max}(mt);
    }
};

int main()
{
    // Print 10 random numbers in the range 1..6 (like rolling a die).
    for (int count{ 1 }; count <= 10; ++count)
        std::cout << Random::get(1, 6) << '\t';

    std::cout << '\n';

    return 0;
}
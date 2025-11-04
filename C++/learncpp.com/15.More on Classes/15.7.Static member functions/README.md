# Random (static members) — 15.7 Static member functions\

This example demonstrates:\
- a class with static member functions and static data,\
- initializing a static inline std::mt19937 engine using a helper function,\
- generating uniformly distributed integers using std::uniform_int_distribution.\

It implements class `Random` with a shared `std::mt19937` engine and a `get(min, max)` static method.\
The program prints 10 random numbers in the range 1..6.

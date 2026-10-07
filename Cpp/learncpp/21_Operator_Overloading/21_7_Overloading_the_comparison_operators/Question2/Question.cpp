#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// A simple Car class that can be sorted by make and model.
class Car
{
private:
	std::string m_make;
	std::string m_model;

public:
	Car(std::string_view make, std::string_view model)
		: m_make{ make }, m_model{ model }
	{
	}

	// We need a comparison operator for sorting and a stream insertion operator
	// to print the car objects nicely.
	friend bool operator<(const Car& c1, const Car& c2);
	friend std::ostream& operator<<(std::ostream& out, const Car& c1);
};

// Sort cars alphabetically by make, and then by model when the make matches.
bool operator<(const Car& c1, const Car& c2)
{
	if (c1.m_make!=c2.m_make)
	{
		return c1.m_make<c2.m_make;
	}
	else
	{
		return c1.m_model<c2.m_model;
	}
}

// Print the car in a readable format: (make, model).
std::ostream& operator<<(std::ostream& out, const Car& c1){
	out << "(" << c1.m_make << ", " << c1.m_model << ")";
	return out;
}

int main()
{
	std::vector<Car> cars{
		{ "Toyota", "Corolla" },
		{ "Honda", "Accord" },
		{ "Toyota", "Camry" },
		{ "Honda", "Civic" }
	};

	// std::sort requires an overloaded operator<.
	std::sort(cars.begin(), cars.end());

	// Printing each car requires an overloaded operator<<.
	for (const auto& car : cars)
		std::cout << car << '\n';

	return 0;
}
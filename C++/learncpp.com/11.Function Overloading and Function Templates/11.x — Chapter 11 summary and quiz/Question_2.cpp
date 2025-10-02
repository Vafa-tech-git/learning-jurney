#include <iostream>

// Template for add function in order to add any type of number.
template <typename addt>
addt add(addt addnumber1, addt addnumber2)
{
  return addnumber1 + addnumber2;
}
// Template for mult function in order to multiply any type of number.
template <typename multT>
multT mult(multT multnumber1, int multnumber2)
{
  return multnumber1 * multnumber2;
}
// Template for sub function in order to minus any type of number.
// Could use abreviation function auto sub(auto subn1, auto subn2) instead of this.
template<typename t1, typename t2>
auto sub(t1 subn1, t2 subn2)
{
  return subn1 - subn2;
}

int main()
{
// Exemples for add function.
  std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';
// Exemples for mult function.
  std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';
// Exemples for sub function.
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}
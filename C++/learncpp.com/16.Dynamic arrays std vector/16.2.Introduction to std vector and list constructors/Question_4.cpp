#include <iostream>
#include <vector>

int main(){

std::vector<int> sum(3);

std::cout << "Give 3 integral values separated by a space: ";
std::cin >> sum[0] >> sum[1] >> sum[2];

std::cout << "The sum is: " << sum[0]+sum[1]+sum[2] << '\n';
std::cout << "The product is: " << sum[0]*sum[1]*sum[2];

return 0;
}
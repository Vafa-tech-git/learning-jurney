#include <algorithm> // for std::swap
#include <iostream>

void sort2(int& lesser, int& greater){
    // If the values are not sorted, we need to swap them so they are
    if (lesser > greater)
        std::swap(lesser, greater);

    // If we wrote our own swap instead, we could do so like this:
    // int swap { lesser };
    // lesser = greater;
    // greater = swap;

}

int main(){

    int x { 7 };
    int y { 5 };

    std::cout << x << ' ' << y << '\n';

    sort2(x, y); // make sure sort works when values need to be swapped
    std::cout << x << ' ' << y << '\n';

    sort2(x, y); // make sure sort works when values don't need to be swapped
    std::cout << x << ' ' << y << '\n';

return 0;
}
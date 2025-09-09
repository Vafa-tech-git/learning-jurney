#include <iostream>

float biggerinput()
{

    float input;
    std::cout << "Dati un numar real: ";
    std::cin >> input;

 return input;
}

float smallerinput()
{

    float input;
    std::cout << "Dati un alt numar real mai mic: ";
    std::cin >> input;
    
 return input;
}

int main()
{

    float bigger { biggerinput() }, smaller { smallerinput() };

    
     if ((bigger < smaller))
     {

        float temp;
        temp = bigger;
        bigger = smaller;
        smaller = temp;
     }
    

    std::cout << "Numarul mai mic este " << smaller << '\n';
    std::cout << "Numarul mai mare este " << bigger << '\n';

 return 0;
}
// ex02/main.cpp
#include "Functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "---- Iteration " << i << " ----" << std::endl;

        Base *p = generate();

        identify(p);   // version pointeur
        identify(*p);  // version référence

        delete p;
    }

    return 0;
}

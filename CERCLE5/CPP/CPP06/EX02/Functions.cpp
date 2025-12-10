// ex02/Functions.cpp
#include "Functions.hpp"
#include "Derived.hpp"
#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time

Base *generate(void)
{
    int r = std::rand() % 3;

    switch (r)
    {
    case 0:
        std::cout << "generate(): created A" << std::endl;
        return new A();
    case 1:
        std::cout << "generate(): created B" << std::endl;
        return new B();
    default:
        std::cout << "generate(): created C" << std::endl;
        return new C();
    }
}

// Version pointeur
void identify(Base *p)
{
    if (p == 0)
    {
        std::cout << "identify(Base*): null pointer" << std::endl;
        return;
    }

    if (dynamic_cast<A *>(p) != 0)
        std::cout << "identify(Base*): A" << std::endl;
    else if (dynamic_cast<B *>(p) != 0)
        std::cout << "identify(Base*): B" << std::endl;
    else if (dynamic_cast<C *>(p) != 0)
        std::cout << "identify(Base*): C" << std::endl;
    else
        std::cout << "identify(Base*): Unknown type" << std::endl;
}

// Version référence (interdiction d'utiliser des pointeurs : on ne stocke pas d'adresse)
void identify(Base &p)
{
    // Ici, on utilise dynamic_cast sur des références.
    // En cas d'échec, dynamic_cast lève une exception de type std::bad_cast,
    // mais on la capture via catch(...) pour éviter d'inclure <typeinfo>.
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "identify(Base&): A" << std::endl;
        return;
    }
    catch (...)
    {
    }

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "identify(Base&): B" << std::endl;
        return;
    }
    catch (...)
    {
    }

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "identify(Base&): C" << std::endl;
        return;
    }
    catch (...)
    {
    }

    std::cout << "identify(Base&): Unknown type" << std::endl;
}

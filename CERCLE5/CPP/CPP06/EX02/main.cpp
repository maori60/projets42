// ex02/main.cpp
#include "Functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static void sep()
{
    std::cout << "------------------------------------------------------------\n";
}

static void header()
{
    sep();
    std::cout << "CPP06 - ex02: Identify real type (dynamic_cast)\n";
    sep();
    std::cout
        << "Goal:\n"
        << "  - generate() creates an object of type A, B, or C\n"
        << "  - identify(Base*) must detect the REAL type using dynamic_cast on POINTERS\n"
        << "  - identify(Base&) must detect the REAL type using dynamic_cast on REFERENCES\n\n"
        << "Key rules:\n"
        << "  - Base must be polymorphic (virtual destructor) so dynamic_cast works correctly.\n"
        << "  - identify(Base*) checks NULL return from dynamic_cast<Derived*>(p)\n"
        << "  - identify(Base&) uses try/catch because dynamic_cast<Derived&>(ref)\n"
        << "    throws an exception when the cast fails.\n"
        << "  - <typeinfo> / std::typeinfo is forbidden.\n";
    sep();
}

static void explainIteration(int i)
{
    std::cout << "Iteration #" << i << "\n";
    std::cout << "1) generate(): returns Base* but the REAL object is A/B/C\n";
    std::cout << "2) identify(Base*): pointer version -> dynamic_cast returns NULL on failure\n";
    std::cout << "3) identify(Base&): reference version -> dynamic_cast throws on failure\n";
    sep();
}

int main()
{
    header();

    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < 5; ++i)
    {
        explainIteration(i);

        Base *p = generate();
        std::cout << "Returned as Base*  : " << p << "\n";
        sep();

        std::cout << "[Pointer version] identify(Base*)\n";
        std::cout << "Explanation: We test dynamic_cast<A*>(p), dynamic_cast<B*>(p), dynamic_cast<C*>(p).\n"
                  << "If the cast fails, it returns NULL. If it succeeds, we found the type.\n";
        identify(p);
        sep();

        std::cout << "[Reference version] identify(Base&)\n";
        std::cout << "Explanation: We test dynamic_cast<A&>(ref), dynamic_cast<B&>(ref), dynamic_cast<C&>(ref).\n"
                  << "If the cast fails, it THROWS (std::bad_cast). We catch it and try the next.\n";
        identify(*p);
        sep();

        std::cout << "Cleanup: delete p (Base has a virtual destructor -> correct derived destructor call)\n";
        delete p;

        sep();
        std::cout << "\n";
    }

    std::cout << "Conclusion:\n"
              << "  dynamic_cast identifies the REAL runtime type (A/B/C) even when stored as Base*.\n";
    sep();

    return 0;
}

#include "Functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static void sep() { std::cout << "------------------------------------------------------------\n"; }

int main()
{
    sep();
    std::cout << "CPP06 - ex02: Identify real type (dynamic_cast)\n";
    sep();
    std::cout
        << "How it works:\n"
        << "  - generate() returns Base* but real object is A/B/C\n"
        << "  - identify(Base*): dynamic_cast<Derived*>(p) -> NULL if failed\n"
        << "  - identify(Base&): dynamic_cast<Derived&>(p) -> throws if failed\n"
        << "Note:\n"
        << "  - Same address can appear multiple times because the allocator may reuse memory after delete.\n";
    sep();

    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < 5; ++i)
    {
        Base *p = generate();

        std::cout << "#" << i
                  << " | addr=" << p
                  << " | identify(ptr)=";
        identify(p);

        std::cout << "    "
                  << "identify(ref)=";
        identify(*p);

        sep();
        delete p;
    }

    std::cout << "Conclusion: dynamic_cast finds the real runtime type safely.\n";
    sep();
    return 0;
}

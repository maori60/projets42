#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void printSection(const std::string &title)
{
    std::cout << "\n========================================\n";
    std::cout << title << "\n";
    std::cout << "========================================\n";
}

template <typename Container>
static void testEasyFind(const std::string &containerName, Container &c, int value)
{
    std::cout << "[EasyFind] " << containerName
              << " | search " << value << " -> ";

    try
    {
        // IMPORTANT: ton easyfind() renvoie visiblement un const_iterator
        typename Container::const_iterator it = easyfind(c, value);
        std::cout << "FOUND (value=" << *it << ")\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "NOT FOUND (" << e.what() << ")\n";
    }
}

int main()
{
    printSection("EX00 - EasyFind (clear tests)");

    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);
    printSection("Test std::vector<int>");
    testEasyFind("std::vector<int>", v, 5);
    testEasyFind("std::vector<int>", v, 20);

    std::list<int> l;
    for (int i = 0; i < 20; ++i)
        l.push_back(i);
    printSection("Test std::list<int>");
    testEasyFind("std::list<int>", l, 0);
    testEasyFind("std::list<int>", l, 1000);

    std::deque<int> d;
    for (int i = 0; i < 350; ++i)
        d.push_back(i);
    printSection("Test std::deque<int>");
    testEasyFind("std::deque<int>", d, 349);
    testEasyFind("std::deque<int>", d, 560);

    std::cout << "\n[EasyFind] Done.\n";
    return 0;
}

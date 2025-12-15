#include <iostream>
#include "MutantStack.hpp"

static void printSection(const std::string &title)
{
    std::cout << "\n========================================\n";
    std::cout << title << "\n";
    std::cout << "========================================\n";
}

template <typename T>
static void printStackForward(MutantStack<T> &m)
{
    std::cout << "Forward iteration: ";
    typename MutantStack<T>::iterator it = m.begin();
    typename MutantStack<T>::iterator ite = m.end();
    for (; it != ite; ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

template <typename T>
static void printStackReverse(MutantStack<T> &m)
{
    std::cout << "Reverse iteration: ";
    typename MutantStack<T>::reverse_iterator it = m.rbegin();
    typename MutantStack<T>::reverse_iterator ite = m.rend();
    for (; it != ite; ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

int main()
{
    printSection("EX02 - MutantStack");

    MutantStack<int> mstack;

    printSection("Push elements (std::stack behavior)");
    mstack.push(5);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Top element   : " << mstack.top() << "\n";
    std::cout << "Stack size   : " << mstack.size() << "\n";

    printSection("Iterator test (begin / end)");
    printStackForward(mstack);

    printSection("Reverse iterator test (rbegin / rend)");
    printStackReverse(mstack);

    printSection("Pop test");
    mstack.pop();
    std::cout << "After pop(), new top: " << mstack.top() << "\n";
    std::cout << "New size            : " << mstack.size() << "\n";

    printSection("Iterators after pop()");
    printStackForward(mstack);

    std::cout << "\n[MutantStack] Done.\n";
    return 0;
}

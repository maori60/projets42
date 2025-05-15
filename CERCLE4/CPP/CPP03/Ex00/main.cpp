#include "ClapTrap.hpp"

int main() {
    ClapTrap john("John");
    ClapTrap jane("Jane");

    john.attack("a tree");
    john.takeDamage(5);
    john.beRepaired(3);
    john.attack("Jane");
    john.takeDamage(8);
    john.beRepaired(4);

    return 0;
}

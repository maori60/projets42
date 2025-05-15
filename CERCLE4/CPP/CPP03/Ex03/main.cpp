#include "DiamondTrap.hpp"

int main() {
    DiamondTrap d("Diana");

    d.attack("a rock");
    d.takeDamage(42);
    d.beRepaired(21);
    d.highFivesGuys();
    d.guardGate();
    d.whoAmI();

    return 0;
}

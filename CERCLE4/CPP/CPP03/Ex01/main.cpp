#include "ScavTrap.hpp"

int main() {
    ScavTrap sc("Serena");

    sc.attack("the intruder");
    sc.takeDamage(40);
    sc.beRepaired(20);
    sc.guardGate();

    ScavTrap clone(sc);
    clone.attack("another target");

    ScavTrap assigned("Temp");
    assigned = sc;
    assigned.guardGate();

    return 0;
}

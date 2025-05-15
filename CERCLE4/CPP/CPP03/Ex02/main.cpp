#include "FragTrap.hpp"

int main() {
    FragTrap ft("Fraggie");

    ft.attack("a tree");
    ft.takeDamage(40);
    ft.beRepaired(20);
    ft.highFivesGuys();

    FragTrap copy(ft);
    copy.attack("another enemy");

    FragTrap assigned("Placeholder");
    assigned = ft;
    assigned.highFivesGuys();

    return 0;
}

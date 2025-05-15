#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    Animal* zoo[4];
    for (int i = 0; i < 2; i++) zoo[i] = new Dog();
    for (int i = 2; i < 4; i++) zoo[i] = new Cat();
    for (int i = 0; i < 4; i++) zoo[i]->makeSound();
    for (int i = 0; i < 4; i++) delete zoo[i];

    Dog basic;
    basic.setIdea(0, "Hunt the intruder!");
    Dog copy = basic;
    basic.setIdea(0, "Protect the territory!");

    std::cout << "Basic idea: " << basic.getIdea(0) << std::endl;
    std::cout << "Copied idea: " << copy.getIdea(0) << std::endl;

    return 0;
}

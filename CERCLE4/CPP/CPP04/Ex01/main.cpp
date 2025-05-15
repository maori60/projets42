#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int size = 4;
    Animal* zoo[size];

    for (int i = 0; i < size / 2; i++)
        zoo[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        zoo[i] = new Cat();

    for (int i = 0; i < size; i++)
        zoo[i]->makeSound();

    std::cout << "--- Deleting animals ---" << std::endl;
    for (int i = 0; i < size; i++)
        delete zoo[i];

    std::cout << "--- Deep copy test ---" << std::endl;
    Dog basic;
    basic.setIdea(0, "Catch the ball!");
    Dog copy = basic;
    basic.setIdea(0, "Dig a hole!");
    std::cout << "Basic Dog Idea: " << basic.getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea: " << copy.getIdea(0) << std::endl;

    return 0;
}

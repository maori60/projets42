/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 01:33:45 by vbui              #+#    #+#             */
/*   Updated: 2025/07/16 01:33:47 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) {
    this->type = "Dog";
    std::cout << "Dog constructed!" << std::endl;
}

Dog::Dog(const Dog& other)
    : Animal(other), brain(new Brain(*other.brain)) {
    this->type = other.type;
    std::cout << "Dog copied!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        this->type = other.type;

        if (this->brain && other.brain)
            *this->brain = *other.brain;
        else if (!this->brain && other.brain)
            this->brain = new Brain(*other.brain);
        // sinon : les deux sont nullptr → rien à faire
    }
    std::cout << "Dog assigned!" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destroyed!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! 🐶" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    if (this->brain)
        this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    if (this->brain)
        return this->brain->getIdea(index);
    return "";
}

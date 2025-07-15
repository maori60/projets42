/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 01:26:10 by vbui              #+#    #+#             */
/*   Updated: 2025/07/16 01:28:45 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) {
    this->type = "Cat";
    std::cout << "Cat constructed!" << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other), brain(new Brain(*other.brain)) {
    this->type = other.type;
    std::cout << "Cat copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        this->type = other.type;

        if (this->brain && other.brain)
            *this->brain = *other.brain;
        else if (!this->brain && other.brain)
            this->brain = new Brain(*other.brain);
        // sinon les deux sont nullptr : rien à faire
    }
    std::cout << "Cat assigned!" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destroyed!" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! 🐱" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    if (this->brain)
        this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    if (this->brain)
        return this->brain->getIdea(index);
    return "";
}

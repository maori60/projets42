/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:13:25 by vbui              #+#    #+#             */
/*   Updated: 2025/06/18 00:10:21 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

// Fonction utilitaire : demande une saisie non vide
void Contact::promptField(const std::string& prompt, std::string& field) {
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, field);
        if (std::cin.eof()) {
            std::cout << "\nEntrée interrompue. Fin du programme." << std::endl;
            std::exit(1);
        }
        if (!field.empty())
            break;
        std::cout << "Ce champ ne peut pas être vide. Réessayez." << std::endl;
    }
}

void Contact::setContact() {
    promptField("First name: ", first_name);
    promptField("Last name: ", last_name);
    promptField("Nickname: ", nickname);
    promptField("Phone number: ", phone_number);
    promptField("Darkest secret: ", darkest_secret);
}

std::string Contact::formatField(const std::string& str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::displayShort(int index) const {
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << formatField(first_name) << "|";
    std::cout << std::setw(10) << formatField(last_name) << "|";
    std::cout << std::setw(10) << formatField(nickname) << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First name:     " << first_name << std::endl;
    std::cout << "Last name:      " << last_name << std::endl;
    std::cout << "Nickname:       " << nickname << std::endl;
    std::cout << "Phone number:   " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

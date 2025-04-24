/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:13:25 by vbui              #+#    #+#             */
/*   Updated: 2025/02/03 21:14:26 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip> // Pour l'affichage formaté

void Contact::setContact() {
    std::cout << "First name: ";
    std::getline(std::cin, first_name);
    std::cout << "Last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkest_secret);
}

void Contact::displayShort(int index) const {
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << "|";
    std::cout << std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << "|";
    std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

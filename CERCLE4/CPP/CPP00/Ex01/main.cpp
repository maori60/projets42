/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:13:45 by vbui              #+#    #+#             */
/*   Updated: 2025/02/04 07:26:48 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Entrez une commande (ADD, SEARCH, EXIT) : ";
        std::getline(std::cin, command);

        if (command == "ADD" || command == "add") {
            phoneBook.addContact();
        } else if (command == "SEARCH" || command == "search") {
            phoneBook.searchContact();
        } else if (command == "EXIT" || command == "exit") {
            break;
        }
        else {
            std::cout << "Commande invalide." << std::endl;
        }
    }

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:13:45 by vbui              #+#    #+#             */
/*   Updated: 2025/06/18 00:00:50 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <csignal>
#include <cstdlib> // pour exit

// Handler pour gérer Ctrl+C (SIGINT)
void handleSigint(int signum) {
    std::cout << "\nInterruption (Ctrl+C) captée. Nettoyage...\n";
    std::cin.rdbuf(0);
    std::cout.rdbuf(0);
    exit(signum); // version C++98
}

int main() {
    std::signal(SIGINT, handleSigint);

    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Entrez une commande (ADD, SEARCH, EXIT) : ";
        std::getline(std::cin, command);

        if (std::cin.eof()) {
            std::cout << "\nEntrée interrompue (EOF). Fin du programme." << std::endl;
            break;
        }
        if (std::cin.fail()) {
            std::cerr << "Erreur de lecture. Sortie." << std::endl;
            break;
        }

        if (command == "ADD" || command == "add")
            phoneBook.addContact();
        else if (command == "SEARCH" || command == "search")
            phoneBook.searchContact();
        else if (command == "EXIT" || command == "exit")
            break;
        else
            std::cout << "Commande invalide." << std::endl;
    }

    // Libération explicite pour Valgrind
    std::cin.rdbuf(0);
    std::cout.rdbuf(0);

    return 0;
}

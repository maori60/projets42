/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:13:50 by vbui              #+#    #+#             */
/*   Updated: 2025/06/11 19:17:46 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : oldest(0), count(0) {}

void PhoneBook::addContact() {
    contacts[oldest].setContact();
    std::cout << "Contact ajouté à l'index : " << oldest << std::endl;

    oldest = (oldest + 1) % 8;  // Tourne en boucle de 0 à 7

    if (count < 8) {
        count++;
    }

    std::cout << "Prochain contact remplacera l'index : " << oldest << std::endl;
    std::cout << "Nombre total de contacts enregistrés : " << count << std::endl;
}



void PhoneBook::searchContact() const 
{
    if (count == 0) {
        std::cout << "Le répertoire est vide." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;

    for (int i = 0; i < count; i++) {
        contacts[i].displayShort(i);
    }
    
    int index;

    while (true)
    {
        
        std::cout << "Entrez l'index du contact à afficher : ";
    
        std::cin >> index;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Erreur : veuillez entrer un nombre valide." << std::endl;
            continue;
        }
        
        std::cin.ignore(1000, '\n');//obligatoire pour ignorer le saut à la ligne au cas où if est true
    
        if (index < 0 || index >= count) 
        {
            std::cout << "Index invalide." << std::endl;
        } 
        else 
        {
            contacts[index].displayFull();
            break;
        }
    } 
}
    

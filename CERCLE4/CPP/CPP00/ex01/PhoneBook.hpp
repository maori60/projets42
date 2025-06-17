/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:13:53 by vbui              #+#    #+#             */
/*   Updated: 2025/02/03 21:14:14 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class Contact;  // Déclaration avancée : dit au compilateur que Contact existe

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8]; 
    int oldest;
    int count;

public:
    PhoneBook();
    void addContact();
    void searchContact() const;
};

#endif

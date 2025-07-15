/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:15:39 by vbui              #+#    #+#             */
/*   Updated: 2025/07/01 20:26:18 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie* newZombie(std::string name);
// void randomChump(std::string name);

int main() {
    Zombie* z = newZombie("HeapZombie");
    z->announce();
    delete z;

    randomChump("StackZombie");

    return 0;
}

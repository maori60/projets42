/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:16:02 by vbui              #+#    #+#             */
/*   Updated: 2025/07/01 20:21:58 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int size = 5;
    Zombie* horde = zombieHorde(size, "Walker");

    if (horde) {
        for (int i = 0; i < size; i++) {
            horde[i].announce();
        }
        delete[] horde;
    }

    return 0;
}

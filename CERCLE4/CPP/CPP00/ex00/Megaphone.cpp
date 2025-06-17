/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:57:11 by vbui              #+#    #+#             */
/*   Updated: 2025/05/16 23:02:32 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    int j = 1; 
    
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        while (j < argc)
        {
            int i = 0;
            while (argv[j][i]) 
            {
                if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
                    argv[j][i] = argv[j][i] - 32; 
                
                std::cout.write(&argv[j][i], 1);
                i++;
            }          
            j++;
        }
    }

    std::cout << std::endl;
    return 0;
}

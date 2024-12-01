/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:38:26 by budacapoeir       #+#    #+#             */
/*   Updated: 2023/11/24 15:55:39 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

/*la fonction bzero remet a 0 les 'n' premier octet du bloc pointe par 's' 
(octet contenant '\0') */

/*
#include <stdio.h>
#include <string.h>

// Votre fonction ft_bzero
void ft_bzero(void *s, size_t n)
{
    size_t i = 0;
    while (i < n)
    {
        *(unsigned char *)(s + i) = 0;
        i++;
    }
}

int main()
{
    char str[50];

    // Initialiser le tableau avec des caractères 'a'
    memset(str, 'a', sizeof(str));

    // Appeler ft_bzero pour mettre à zéro les 10 premiers caractères
    ft_bzero(str, 10);

    // Afficher le tableau après l'appel de ft_bzero
    for (int i = 0; i < 50; i++) {
        // Afficher un point pour les caractères nuls pour une meilleure visibilité
        printf("%c", str[i] ? str[i] : '.');
    }
    printf("\n");

    return 0;
}

*/
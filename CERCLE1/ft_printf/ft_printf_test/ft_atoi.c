/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:37:29 by budacapoeir       #+#    #+#             */
/*   Updated: 2023/11/24 15:43:26 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		nbr;
	int		sign;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}

/*La fonction atoi() convertit le début de la chaîne 
pointée par str en entier de type int . Le résultat est identique à un appel
strtol(nptr, (char **) NULL, 10); à la différence que atoi()
 ne détecte pas d'erreur.

Les fonctions atol() et atoll() se comportent comme atoi(), sauf qu'el
les convertissent la portion initiale de la chaîne dans leur type de 
retour long ou long long. atoq() est un nom obsolète pour atoll().  
*/

/*
#include <stdio.h>

int ft_atoi(const char *str); // Prototype de votre fonction

int main() {
    char str[100]; // Déclare un tableau de caractères pour stocker la chaîne entrée par l'utilisateur

    printf("Entrez une chaîne de caractères pour la conversion en entier :\n");
    fgets(str, sizeof(str), stdin); // Lit la chaîne de caractères de l'entrée standard

    int result = ft_atoi(str); // Appelle la fonction ft_atoi et stocke le résultat

    printf("La chaîne convertie en entier est : %d\n", result); // Affiche le résultat

    return 0;
}
*/

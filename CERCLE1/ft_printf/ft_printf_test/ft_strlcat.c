/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:24:29 by budacapoeir       #+#    #+#             */
/*   Updated: 2023/11/24 15:51:32 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;
	size_t	j;

	index = ft_strlen(s);
	if (dstsize != 0)
	{
		dst_len = ft_strlen(d);
		dstsize -= 1;
		i = dst_len;
		j = 0;
		while (i < dstsize && s[j])
   			d[i++] = s[j++];
		if (dstsize + 1 > dst_len)
		{
			d[i] = '\0';
			index += dst_len;
		}
		else
				index += dstsize + 1;
	}
	return (index);
}

/*
#include <stdio.h>

size_t ft_strlen(const char *str);
size_t ft_strlcat(char *d, const char *s, size_t dstsize);

int main() {
    char dest[50] = "Hello, ";  // Chaîne de destination avec un espace à la fin
    const char src[] = "World!"; // Chaîne source

    // Calculer la taille totale du tampon de destination
    size_t dest_size = sizeof(dest);

    // Appeler ft_strlcat
    size_t result = ft_strlcat(dest, src, dest_size);

    // Afficher le résultat de la concaténation et la valeur de retour
    printf("Résultat de la concaténation : %s\n", dest);
    printf("Longueur totale requise : %zu\n", result);

    return 0;
}

*/
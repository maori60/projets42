/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:13 by vbui              #+#    #+#             */
/*   Updated: 2025/01/14 20:47:38 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient des fonctions utilitaires pour gérer la sortie standard, 
** telles que l'écriture de caractères, de chaînes de caractères et de nombres 
** dans un descripteur de fichier.
** Il inclut les fonctions suivantes :
** - Écrire un caractère dans un descripteur de fichier donné (ft_putchar_fd)
** - Écrire une chaîne de caractères dans un descripteur de fichier donné (ft_putstr_fd)
** - Écrire un entier long dans un descripteur de fichier donné (ft_putnbr_fd)
** - Calculer la longueur d'une chaîne de caractères (ft_strlen)
*/

#include "../include/philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0)
	{
		while (s && *s)
		{
			write(fd, &*s, 1);
			s++;
		}
	}
}

void	ft_putnbr_fd(long int ln, int fd)
{
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
	}
	if (ln >= 10)
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
	else
	{
		if (fd >= 0)
			ft_putchar_fd(ln + 48, fd);
	}
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

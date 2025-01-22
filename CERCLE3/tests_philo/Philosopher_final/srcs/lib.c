/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:13 by vbui              #+#    #+#             */
/*   Updated: 2025/01/15 13:57:42 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient des fonctions utilitaires pour gérer la sortie standard,
** telles que l'écriture de caractères, de chaînes de caractères et de nombres
** dans un descripteur de fichier. Il inclut également une fonction pour calculer
** la longueur d'une chaîne de caractères.
*/

#include "../include/philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd >= 0)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(long int ln, int fd)
{
	char	buf[20];
	int		i;

	i = 19;
	if (fd < 0)
		return ;
	buf[i--] = '\0';
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln = -ln;
	}
	if (ln == 0)
		ft_putchar_fd('0', fd);
	while (ln > 0)
	{
		buf[i--] = '0' + (ln % 10);
		ln /= 10;
	}
	ft_putstr_fd(&buf[i + 1], fd);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

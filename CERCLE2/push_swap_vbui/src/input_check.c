/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:31:00 by vbui              #+#    #+#             */
/*   Updated: 2024/06/10 16:38:50 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* arg_is_number:
    Vérifie si l'argument est un nombre. +1, 1 et -1 sont tous des 
	nombres valides.
    Retourne : 1 si l'argument est un nombre, 0 sinon.
*/
int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* have_duplicates:
    Vérifie si la liste d'arguments contient des nombres dupliqués.
    Retourne : 1 si un doublon est trouvé, 0 s'il n'y en a pas.
*/
int	have_duplicates(char **av)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		j = i + 1;
		while (av[j])
		{
			if (nb - ft_atoi(av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	have_duplicates_one_arg(char **av)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		j = i + 1;
		while (av[j])
		{
			if (nb - ft_atoi(av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* arg_is_zero:
    Vérifie si l'argument est un zéro pour éviter les doublons 
	comme 0, +0, -0,
    et également 0, 0000, +000, -00000000.
    Retourne : 1 si l'argument est un zéro, 0 s'il contient autre
	 chose qu'un zéro.
*/
int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/* is_correct_input:
    Vérifie si les arguments donnés sont tous des nombres, sans doublons.
    Retourne : 1 si les arguments sont valides, 0 sinon.
*/
int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	return (1);
}

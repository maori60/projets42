/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:31 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 17:40:45 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* skip_space_sign:
*	Skips spaces, '+' and '-' sign characters and sets the
*	is_neg variable if a '-' sign is detected.
*	Used to parse strings representing float values for Julia.
*/
static int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

/* ft_atof:
*	Converts a string into a float (decimal number). Used to parse
*	Julia starting values given as program arguments.
*	Returns the converted double, or -42 in case of error (Julia accepts
*	values between 2.0 and -2.0 only)
*/
double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (nb * is_neg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:45:49 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 11:54:40 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(const char *str)
{
	long	res;
	long	i;
	long	sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10;
		res = res +(str[i] - '0');
		i++;
	}
	return (res * sign);
}

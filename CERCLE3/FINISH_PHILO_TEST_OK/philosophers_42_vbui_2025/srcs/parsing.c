/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:22 by vbui              #+#    #+#             */
/*   Updated: 2025/01/23 11:18:32 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_atoi(const char *str)
{
	long	sum;
	int		i;

	sum = 0;
	i = 0;
	while (str[i])
	{
		if (sum > 2147483647)
			return (-1);
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	if (sum > 2147483647)
		return (-1);
	return ((int)sum);
}

int	ft_numerik(char **argv, int j)
{
	int		i;
	long	val;

	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if ((argv[j][i] < '0' || argv[j][i] > '9')
				|| ft_strlen(argv[j]) > 10)
				return (0);
			i++;
		}
		val = ft_atoi(argv[j]);
		if (val < 0 || val > 2147483647)
			return (0);
		j++;
	}
	return (1);
}

int	parsing_args(int argc, char **argv, t_p *p)
{
	if ((argc == 5 || argc == 6) && ft_numerik(argv, 1))
	{
		p->a.total = ft_atoi(argv[1]);
		p->a.die = ft_atoi(argv[2]);
		p->a.eat = ft_atoi(argv[3]);
		p->a.sleep = ft_atoi(argv[4]);
		if (argc == 6)
			p->a.m_eat = ft_atoi(argv[5]);
		else
			p->a.m_eat = -1;
		if (p->a.total > MAX_PHILO)
		{
			printf("respect number max_philo = 200\n");
			return (0);
		}
		if (p->a.die < 1 || p->a.eat < 1 || p->a.sleep < 1)
			return (0);
		if (p->a.die > 1000 || p->a.eat > 1000 || p->a.sleep > 1000)
		{
			printf("Max: a.die = 1000, a.eat = 1000, a.sleep = 1000\n");
			return (0);
		}
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:22 by vbui              #+#    #+#             */
/*   Updated: 2025/01/15 13:57:42 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier gère l'analyse et l'initialisation des paramètres du programme.
** Il inclut la conversion des arguments, la validation des valeurs numériques,
** l'initialisation des mutex et la configuration des structures de simulation.
*/

#include "../include/philosophers.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	sum;

	sum = 0;
	i = 0;
	while (str[i])
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return ((int)sum);
}

int	ft_numerik(char **argv, int j)
{
	int	i;

	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
			i++;
		}
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
		p->a.m_eat = (argc == 6) ? ft_atoi(argv[5]) : -1;
		if (p->a.total <= 0 || p->a.die <= 0 || p->a.eat <= 0 || p->a.sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

void	mutex_initialization(t_p *p)
{
	pthread_mutex_init(&p->a.write_mutex, NULL);
	pthread_mutex_init(&p->a.dead, NULL);
	pthread_mutex_init(&p->a.time_eat, NULL);
	pthread_mutex_init(&p->a.finish, NULL);
}

int	ft_initialization(t_p *p)
{
	int	i;

	p->a.start_t = ft_timer();
	p->a.stop = 0;
	p->a.nb_p_finish = 0;
	mutex_initialization(p);
	i = 0;
	while (i < p->a.total)
	{
		p->ph[i].id = i + 1;
		p->ph[i].ms_eat = p->a.start_t;
		p->ph[i].nb_eat = 0;
		p->ph[i].finish = 0;
		pthread_mutex_init(&p->ph[i].left_f, NULL);
		p->ph[i].right_f = (i == p->a.total - 1) ? &p->ph[0].left_f : &p->ph[i + 1].left_f;
		i++;
	}
	return (1);
}

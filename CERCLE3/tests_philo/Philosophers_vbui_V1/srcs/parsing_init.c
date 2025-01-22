/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:22 by vbui              #+#    #+#             */
/*   Updated: 2025/01/14 20:55:56 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient des fonctions pour analyser et initialiser les paramètres
** du programme Philosopher. Les principales fonctions sont :
** - `ft_atoi` : Convertit une chaîne de caractères en entier.
** - `numeric` : Vérifie que tous les arguments sont numériques et respectent les contraintes.
** - `parse_args` : Parse les arguments d'entrée et les valide.
** - `init_mutex` : Initialise les mutex nécessaires pour la synchronisation des philosophes.
** - `initialize` : Initialise les variables de simulation, les philosophes, et leurs fourchettes.
*/

#include "../include/philosophers.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	sum;

	sum = 0;
	i = -1;
	while (str[++i])
		sum = (sum * 10) + (str[i] - 48);
	return (sum);
}

int	numeric(char **argv, int i, int j)
{
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_p *p)
{
	if ((argc == 5 || argc == 6) && numeric(argv, 0, 1))
	{
		p->a.total = ft_atoi(argv[1]);
		p->a.die = ft_atoi(argv[2]);
		p->a.eat = ft_atoi(argv[3]);
		p->a.sleep = ft_atoi(argv[4]);
		p->a.m_eat = -1;
		if (argc == 6)
			p->a.m_eat = ft_atoi(argv[5]);
		if (p->a.total <= 0 || p->a.die <= 0 || p->a.eat <= 0 \
			|| p->a.sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

void	init_mutex(t_p *p)
{
	pthread_mutex_init(&p->a.write_mutex, NULL);
	pthread_mutex_init(&p->a.dead, NULL);
	pthread_mutex_init(&p->a.time_eat, NULL);
	pthread_mutex_init(&p->a.finish, NULL);
}

int	initialize(t_p *p)
{
	int	i;

	i = 0;
	p->a.start_t = ft_timer();
	p->a.stop = 0;
	p->a.nb_p_finish = 0;
	init_mutex(p);
	while (i < p->a.total)
	{
		p->ph[i].id = i + 1;
		p->ph[i].ms_eat = p->a.start_t;
		p->ph[i].nb_eat = 0;
		p->ph[i].finish = 0;
		p->ph[i].right_f = NULL;
		pthread_mutex_init(&p->ph[i].left_f, NULL);
		if (p->a.total == 1)
			return (1);
		if (i == p->a.total - 1)
			p->ph[i].right_f = &p->ph[0].left_f;
		else
			p->ph[i].right_f = &p->ph[i + 1].left_f;
		i++;
	}
	return (1);
}

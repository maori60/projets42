/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:22 by vbui              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/21 05:40:19 by vbui             ###   ########.fr       */
=======
/*   Updated: 2025/01/21 08:00:15 by vbui             ###   ########.fr       */
>>>>>>> 10e5ef6 (reglage time)
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
	long	sum;
	int		i;

	sum = 0;
	i = 0;
	while (str[i])
	{
		// Ajoute une vérification pour éviter les dépassements
		if (sum > 2147483647)
			return (-1);
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	// Vérifie à nouveau après le calcul final
	if (sum > 2147483647)
		return (-1);
	return ((int)sum);
}



// int	ft_atoi(const char *str)
// {
// 	int		i;
// 	long	sum;

// 	sum = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		sum = (sum * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return ((int)sum);
// }

// int	ft_numerik(char **argv, int j)
// {
// 	int		i;
// 	long	value;

// 	while (argv[j])
// 	{
// 		i = 0;
// 		while (argv[j][i])
// 		{
// 			// Vérifie que chaque caractère est un chiffre
// 			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
// 				return (0);
// 			i++;
// 		}
// 		// Vérifie que la valeur entière est valide (pas de dépassement ou valeur négative)
// 		value = ft_atoi(argv[j]);
// 		if (value < 0 || value > 2147483647)
// 			return (0);
// 		j++;
// 	}
// 	return (1);
// }

int	ft_numerik(char **argv, int j)
{
	int		i;
	long	value;

	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			// Vérifie que chaque caractère est un chiffre
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
			i++;
		}
		// Vérifie que la valeur entière est valide (pas de dépassement ou valeur négative)
		value = ft_atoi(argv[j]);
		if (value < 0 || value > 2147483647)
			return (0);
		j++;
	}
	return (1);
}

// int	ft_numerik(char **argv, int j)
// {
// 	int	i;

// 	while (argv[j])
// 	{
// 		i = 0;
// 		while (argv[j][i])
// 		{
// 			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
// 				return (0);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (1);
// }

// int	parsing_args(int argc, char **argv, t_p *p)
// {
// 	if ((argc == 5 || argc == 6) && ft_numerik(argv, 1))
// 	{
// 		p->a.total = ft_atoi(argv[1]);
// 		p->a.die = ft_atoi(argv[2]);
// 		p->a.eat = ft_atoi(argv[3]);
// 		p->a.sleep = ft_atoi(argv[4]);
// 		p->a.m_eat = (argc == 6) ? ft_atoi(argv[5]) : -1;
// 		if (p->a.total <= 0 || p->a.die <= 0 || p->a.eat <= 0 || p->a.sleep <= 0)
// 			return (0);
// 		return (1);
// 	}
// 	return (0);
// }

int	parsing_args(int argc, char **argv, t_p *p)
{
	if ((argc == 5 || argc == 6) && ft_numerik(argv, 1))
	{
		p->a.total = ft_atoi(argv[1]);
		p->a.die = ft_atoi(argv[2]);
		p->a.eat = ft_atoi(argv[3]);
		p->a.sleep = ft_atoi(argv[4]);
		p->a.m_eat = (argc == 6) ? ft_atoi(argv[5]) : -1;

		// Vérification des bornes
		if (p->a.total <= 0 || p->a.die <= 0 || p->a.eat <= 0 || p->a.sleep <= 0)
			return (0);
		if (p->a.die > 1000000 || p->a.eat > 1000000 || p->a.sleep > 1000000)
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
	i = 0;
	p->a.start_t = ft_timer();
	p->a.stop = 0;
	p->a.nb_p_finish = 0;
	mutex_initialization(p);
	i = 0;
	while (i < p->a.total)
	{	
<<<<<<< HEAD
		p->ph[i].thread_id = -1;
		p->ph[i].id = i + 1;
		p->ph[i].ms_eat = p->a.start_t;
		p->ph[i].nb_eat = -1;
=======
		//p->ph[i].thread_id = -1;
		p->ph[i].id = i + 1;
		p->ph[i].ms_eat = p->a.start_t;
		p->ph[i].nb_eat = 0;
>>>>>>> 10e5ef6 (reglage time)
		p->ph[i].finish = 0;
		p->ph[i].right_f = NULL;
		pthread_mutex_init(&p->ph[i].left_f, NULL);
		p->ph[i].right_f = (i == p->a.total - 1) ? &p->ph[0].left_f : &p->ph[i + 1].left_f;
		i++;
	}
	return (1);
}

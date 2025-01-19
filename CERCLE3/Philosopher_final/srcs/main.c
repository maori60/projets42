/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:51:23 by vbui              #+#    #+#             */
/*   Updated: 2025/01/19 14:27:13 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient la fonction principale qui initialise le programme
** et gère l'exécution des philosophes.
*/

#include "../include/philosophers.h"

int	ft_byebye(char *str)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	ft_who_is_died(t_p *p)
{
	pthread_mutex_lock(&p->a.dead);
	if (p->a.stop)
	{
		pthread_mutex_unlock(&p->a.dead);
		return (1);
	}
	pthread_mutex_unlock(&p->a.dead);
	return (0);
}

void	stop_operator(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->a.total)
	{
		pthread_join(p->ph[i].thread_id, NULL);
		pthread_join(p->ph[i].thread_death_id, NULL);
		i++;
	}
	pthread_mutex_destroy(&p->a.write_mutex);
	pthread_mutex_destroy(&p->a.dead);
	pthread_mutex_destroy(&p->a.time_eat);
	pthread_mutex_destroy(&p->a.finish);
	i = 0;
	while (i < p->a.total)
	{
		pthread_mutex_destroy(&p->ph[i].left_f);
		i++;
	}
	free(p->ph);
}

int	main(int argc, char **argv)
{
	t_p	p;

	if (!parsing_args(argc, argv, &p))
		return (ft_byebye("Invalid arguments\n"));
	p.ph = malloc(sizeof(t_phil) * p.a.total);
	if (!p.ph)
		return (ft_byebye("Malloc returned NULL\n"));
	if (!ft_initialization(&p) || !threading(&p))
	{
		free(p.ph);
		return (0);
	}
	stop_operator(&p);
	return (0);
}

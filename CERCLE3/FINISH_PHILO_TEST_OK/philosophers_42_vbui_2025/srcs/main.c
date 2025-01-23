/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:51:23 by vbui              #+#    #+#             */
/*   Updated: 2025/01/23 03:40:58 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
** ft_byebye:
** Prints an error message and returns 0.
*/
int	ft_byebye(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

/*
** ft_who_is_died:
** Not used anymore, but kept for compatibility.
** Could simply call ft_god_supervisor.
*/
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

/*
** main:
** Parses arguments, allocates p->ph,
** initializes, starts threads, then stops.
*/
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

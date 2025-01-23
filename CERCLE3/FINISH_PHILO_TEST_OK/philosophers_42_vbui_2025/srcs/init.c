/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:22 by vbui              #+#    #+#             */
/*   Updated: 2025/01/23 03:47:48 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	init_global_mutex(t_p *p)
{
	pthread_mutex_init(&p->a.write_mutex, NULL);
	pthread_mutex_init(&p->a.dead, NULL);
	pthread_mutex_init(&p->a.time_eat, NULL);
	pthread_mutex_init(&p->a.finish, NULL);
}

static void	init_philosopher(t_p *p, int i)
{
	p->ph[i].id = i + 1;
	p->ph[i].ms_eat = p->a.start_t;
	p->ph[i].nb_eat = 0;
	p->ph[i].finish = 0;
	p->ph[i].pa = &p->a;
	pthread_mutex_init(&p->ph[i].left_f, NULL);
	pthread_mutex_init(&p->ph[i].meal_time_lock, NULL);
	if (i == p->a.total - 1)
		p->ph[i].right_f = &p->ph[0].left_f;
	else
		p->ph[i].right_f = &p->ph[i + 1].left_f;
}

int	ft_initialization(t_p *p)
{
	int	i;

	p->a.stop = 0;
	p->a.nb_p_finish = 0;
	p->a.start_t = ft_timer();
	init_global_mutex(p);
	i = 0;
	while (i < p->a.total)
	{
		init_philosopher(p, i);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/01/23 03:41:18 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
** stop_operator_join:
** Waits for simulation end, then joins philosopher threads.
*/
static void	stop_operator_join(t_p *p)
{
	int	i;

	while (!ft_who_is_died(p))
		ft_usleep(1);
	i = 0;
	while (i < p->a.total)
	{
		pthread_join(p->ph[i].thread_id, NULL);
		if (p->a.total > 1)
			pthread_join(p->ph[i].thread_death_id, NULL);
		i++;
	}
}

/*
** stop_operator_destroy:
** Checks p->a.stop, prints the message if needed,
** then destroys global mutexes.
*/
static void	stop_operator_destroy(t_p *p)
{
	pthread_mutex_lock(&p->a.dead);
	if (p->a.stop == 2)
		printf("Each philosopher has eaten at least %d times.\n", p->a.m_eat);
	pthread_mutex_unlock(&p->a.dead);
	pthread_mutex_destroy(&p->a.write_mutex);
	pthread_mutex_destroy(&p->a.dead);
	pthread_mutex_destroy(&p->a.time_eat);
	pthread_mutex_destroy(&p->a.finish);
}

/*
** stop_operator_free:
** Destroys the left_f of each philosopher and frees p->ph.
*/
static void	stop_operator_free(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->a.total)
	{
		pthread_mutex_destroy(&p->ph[i].left_f);
		i++;
	}
	free(p->ph);
}

/*
** stop_operator:
** Calls the three sub-functions to join threads,
** destroy mutexes, and free memory.
*/
void	stop_operator(t_p *p)
{
	stop_operator_join(p);
	stop_operator_destroy(p);
	stop_operator_free(p);
}

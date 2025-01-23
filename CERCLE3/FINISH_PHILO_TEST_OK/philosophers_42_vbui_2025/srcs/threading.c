/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/01/23 04:02:26 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
** handle_single_philo:
** For one philosopher scenario: 
** takes a fork, waits time_to_die, prints "died", stop=1.
*/
static void	handle_single_philo(t_phil *ph)
{
	ft_status("has taken the fork of death", ph);
	ft_usleep(ph->pa->die);
	ft_status("died", ph);
	ft_god_supervisor(ph, 1);
}

/*
** handle_meals:
** 1) ft_operation => philosopher eats
** 2) increments nb_eat, checks must_eat_count
** 3) returns 1 if ph must exit, 0 otherwise
*/
static int	handle_meals(t_phil *ph)
{
	ft_operation(ph);
	pthread_mutex_lock(&ph->meal_time_lock);
	ph->nb_eat++;
	if (ph->pa->m_eat != -1 && (int)ph->nb_eat >= ph->pa->m_eat)
	{
		ph->finish = 1;
		pthread_mutex_unlock(&ph->meal_time_lock);
		pthread_mutex_lock(&ph->pa->finish);
		ph->pa->nb_p_finish++;
		if (ph->pa->nb_p_finish == ph->pa->total)
			ft_god_supervisor(ph, 2);
		pthread_mutex_unlock(&ph->pa->finish);
		return (1);
	}
	pthread_mutex_unlock(&ph->meal_time_lock);
	return (0);
}

/*
** thread:
** Routine for each philosopher:
** - if only 1 philosopher => handle_single_philo
** - if id is even => small offset
** - while !stop => handle_meals
*/
void	*thread(void *data)
{
	t_phil	*ph;

	ph = (t_phil *)data;
	if (ph->pa->total == 1)
	{
		handle_single_philo(ph);
		return ((void *)0);
	}
	if (ph->id % 2 == 0)
		ft_usleep(ph->pa->eat / 10);
	while (!ft_god_supervisor(ph, 0))
	{
		if (handle_meals(ph) == 1)
			return ((void *)0);
	}
	return ((void *)0);
}

/*
** create_philo_threads:
** Creates thread (main) and finishim (in finishim.c) 
** for each philosopher. Returns 1 on success, 0 if error.
*/
static int	create_philo_threads(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->a.total)
	{
		if (pthread_create(&p->ph[i].thread_id, NULL,
				thread, &p->ph[i]) != 0)
			return (ft_byebye("Pthread did not return 0\n"));
		if (pthread_create(&p->ph[i].thread_death_id, NULL,
				finishim, &p->ph[i]) != 0)
			return (ft_byebye("Pthread finishim did not return 0\n"));
		i++;
	}
	return (1);
}

/*
** threading:
** If total == 1 => only one thread. 
** Otherwise => create two threads per philo:
** - main: routine 'thread'
** - death: routine 'finishim'
*/
int	threading(t_p *p)
{
	if (p->a.total == 1)
	{
		if (pthread_create(&p->ph[0].thread_id, NULL,
				thread, &p->ph[0]) != 0)
			return (ft_byebye("Pthread did not return 0\n"));
		return (1);
	}
	if (!create_philo_threads(p))
		return (0);
	return (1);
}

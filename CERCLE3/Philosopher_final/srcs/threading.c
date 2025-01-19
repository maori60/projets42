/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/01/19 14:16:13 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier gère les threads des philosophes :
** - Surveillance de leur état (finishim).
** - Actions des philosophes (thread).
** - Création des threads (threading).
*/

#include "../include/philosophers.h"

/*
** Vérifie si le philosophe est mort.
** Retourne 1 si oui, 0 sinon.
*/
static int	check_death(t_phil *ph, long int time_since_last_meal)
{
	if (time_since_last_meal >= (long)(ph->pa->die))
	{
		pthread_mutex_lock(&ph->pa->write_mutex);
		ft_status("died\n", ph);
		pthread_mutex_unlock(&ph->pa->write_mutex);
		pthread_mutex_lock(&ph->pa->dead);
		ph->pa->stop = 1;
		pthread_mutex_unlock(&ph->pa->dead);
		return (1);
	}
	return (0);
}

/*
** Vérifie périodiquement si le philosophe est mort.
*/
void	*finishim(void *data)
{
	t_phil		*ph;
	long int	current_time;
	long int	time_since_last_meal;

	ph = (t_phil *)data;
	if (!ph || !ph->pa)
		return (NULL);
	while (!ft_god_supervisor(ph, 0))
	{
		ft_usleep(ph->pa->die + 1);
		pthread_mutex_lock(&ph->pa->time_eat);
		current_time = ft_timer();
		time_since_last_meal = current_time - ph->ms_eat;
		pthread_mutex_unlock(&ph->pa->time_eat);
		if (check_death(ph, time_since_last_meal))
			return (NULL);
	}
	return (NULL);
}

void	*thread(void *data)
{
	t_phil	*phil;

	phil = (t_phil *)data;
	if (phil->id % 2 == 0)
		ft_usleep(phil->pa->eat / 10);
	while (!ft_god_supervisor(phil, 0))
	{
		ft_operation(phil);
		pthread_mutex_lock(&phil->pa->finish);
		phil->nb_eat++;
		if (phil->nb_eat == (unsigned int)phil->pa->m_eat)
		{
			phil->finish = 1;
			phil->pa->nb_p_finish++;
			if (phil->pa->nb_p_finish == phil->pa->total)
			{
				pthread_mutex_lock(&phil->pa->dead);
				phil->pa->stop = 2;
				printf("Philo has eaten at least %d times\n", phil->pa->m_eat);
				pthread_mutex_unlock(&phil->pa->dead);
			}
		}
		pthread_mutex_unlock(&phil->pa->finish);
	}
	return (NULL);
}

int	threading(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->a.total)
	{
		p->ph[i].pa = &p->a;
		if (pthread_create(&p->ph[i].thread_id, NULL, thread, &p->ph[i]) != 0)
			return (ft_byebye("Pthread did not return 0\n"));
		if (pthread_create(&p->ph[i].thread_death_id,
				NULL, finishim, &p->ph[i]) != 0)
			return (ft_byebye("Pthread death did not return 0\n"));
		i++;
	}
	return (1);
}

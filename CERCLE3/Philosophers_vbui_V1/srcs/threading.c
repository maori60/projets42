/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:24 by vbui              #+#    #+#             */
/*   Updated: 2025/01/14 20:55:56 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient les fonctions responsables de la gestion des threads
** dans le programme Philosopher.
** Les principales fonctions sont :
** - `finishim` : Vérifie si un philosophe meurt (fonction de contrôle de la mort).
** - `thread` : Fonction principale des threads des philosophes, qui gère l'exécution de chaque philosophe,
**   y compris la création du thread de la mort et les actions de manger, penser, et dormir.
** - `threading` : Crée les threads pour chaque philosophe et initialise les valeurs nécessaires.
*/

#include "../include/philosophers.h"

void	*finishim(void	*data)
{
	t_philo					*ph;

	ph = (t_philo *)data;
	ft_usleep(ph->pa->die + 1);
	pthread_mutex_lock(&ph->pa->time_eat);
	pthread_mutex_lock(&ph->pa->finish);
	if (!ft_god_supervisor(ph, 0) && !ph->finish && ((ft_timer() - ph->ms_eat) \
		>= (long)(ph->pa->die)))
	{
		pthread_mutex_unlock(&ph->pa->time_eat);
		pthread_mutex_unlock(&ph->pa->finish);
		pthread_mutex_lock(&ph->pa->write_mutex);
		ft_status("meurt\n", ph);
		pthread_mutex_unlock(&ph->pa->write_mutex);
		ft_god_supervisor(ph, 1);
	}
	pthread_mutex_unlock(&ph->pa->time_eat);
	pthread_mutex_unlock(&ph->pa->finish);
	return (NULL);
}

void	*thread(void *data)
{
	t_philo					*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->pa->eat / 10);
	while (!ft_god_supervisor(ph, 0))
	{
		pthread_create(&ph->thread_death_id, NULL, finishim, data);
		ft_operation(ph);
		pthread_detach(ph->thread_death_id);
		if ((int)++ph->nb_eat == ph->pa->m_eat)
		{
			pthread_mutex_lock(&ph->pa->finish);
			ph->finish = 1;
			ph->pa->nb_p_finish++;
			if (ph->pa->nb_p_finish == ph->pa->total)
			{
				pthread_mutex_unlock(&ph->pa->finish);
				ft_god_supervisor(ph, 2);
			}
			pthread_mutex_unlock(&ph->pa->finish);
			return (NULL);
		}
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
		i++;
	}
	return (1);
}

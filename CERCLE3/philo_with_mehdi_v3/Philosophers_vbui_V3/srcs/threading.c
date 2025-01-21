/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:00:00 by vbui              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/21 05:47:36 by vbui             ###   ########.fr       */
=======
/*   Updated: 2025/01/21 08:23:42 by vbui             ###   ########.fr       */
>>>>>>> 10e5ef6 (reglage time)
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier gère les threads des philosophes. Il inclut les fonctions pour :
** - Vérifier si un philosophe meurt (finishim).
** - Gérer les actions des philosophes dans les threads (thread).
** - Créer les threads pour chaque philosophe (threading).
*/

#include "../include/philosophers.h"


/*
void	*finishim(void *data)
{
	t_philo	*ph;
	long int	current_time;

	ph = (t_philo *)data;
	if (!ph || !ph->pa) return NULL; // ajout
	while (!ft_god_supervisor(ph, 0))
	{
		// ft_usleep(5); // Réduit les cycles de la boucle
		ft_usleep(ph->pa->die + 1);
		pthread_mutex_lock(&ph->pa->time_eat);
		current_time = ft_timer();
		if ((current_time - ph->ms_eat) >= (long)(ph->pa->die))
		{
			pthread_mutex_unlock(&ph->pa->time_eat);
			pthread_mutex_lock(&ph->pa->write_mutex);
			ft_status("meurt\n", ph);
			pthread_mutex_unlock(&ph->pa->write_mutex);
			pthread_mutex_lock(&ph->pa->dead);
			ph->pa->stop = 1;
			pthread_mutex_unlock(&ph->pa->dead);
			return (NULL);
		}
		pthread_mutex_unlock(&ph->pa->time_eat);
	}
	return (NULL);
}

*/


<<<<<<< HEAD
void	*finishim(void *data)
{
	t_phil	*ph;
	long int	current_time;
	long int	time_since_last_meal;

	ph = (t_phil *)data;
	if (!ph || !ph->pa)
		return (NULL);
	while (!ft_god_supervisor(ph, 0))
	{
		// Réduit les cycles de la boucle pour vérifier plus fréquemment
		// ft_usleep(5); >> ajout 1er
		ft_usleep(ph->pa->die + 1); //ajout 2e
		// usleep(900);
		// usleep(10);
		// Verrouiller pour lire le dernier temps de repas
		pthread_mutex_lock(&ph->pa->time_eat);
		current_time = ft_timer();
		time_since_last_meal = current_time - ph->ms_eat;
		pthread_mutex_unlock(&ph->pa->time_eat);

		// Vérifier si le philosophe est mort
		if (time_since_last_meal >= (long)(ph->pa->die))
		{
			pthread_mutex_lock(&ph->pa->write_mutex);
			ft_status("meurt\n", ph);
			pthread_mutex_unlock(&ph->pa->write_mutex);

			pthread_mutex_lock(&ph->pa->dead);
			ph->pa->stop = 1;
			pthread_mutex_unlock(&ph->pa->dead);

			return (NULL);
		}
	}

	return (NULL);
}

=======
void *finishim(void *data)
{
    t_phil *ph = (t_phil *)data;

    if (!ph || !ph->pa)
        return (NULL);

    // Temporisation pour vérifier la mort après un délai suffisant
    ft_usleep(ph->pa->die + 1);

    // Vérification des conditions de mort
    pthread_mutex_lock(&ph->pa->time_eat);
    pthread_mutex_lock(&ph->pa->finish);

    if (!ft_god_supervisor(ph, 0) && 
        !ph->finish && 
        (ft_timer() - ph->ms_eat) >= (long)(ph->pa->die))
    {
        pthread_mutex_unlock(&ph->pa->time_eat); // Libère avant de quitter
        pthread_mutex_unlock(&ph->pa->finish);

        // Signale que le philosophe est mort
        pthread_mutex_lock(&ph->pa->write_mutex);
        ft_status("died\n", ph);
        pthread_mutex_unlock(&ph->pa->write_mutex);

        // Déclenche l'arrêt global
        ft_god_supervisor(ph, 1);
        return (NULL);
    }

    // Déverrouille les mutex si aucune condition de mort n'est rencontrée
    pthread_mutex_unlock(&ph->pa->finish);
    pthread_mutex_unlock(&ph->pa->time_eat);

    return (NULL);
}


>>>>>>> 10e5ef6 (reglage time)
// void	*finishim(void *data)
// {
// 	t_philo	*ph;

// 	ph = (t_philo *)data;
// 	while (!ft_god_supervisor(ph, 0))
// 	{
// 		ft_usleep(1);
// 		pthread_mutex_lock(&ph->pa->time_eat);
// 		if ((ft_timer() - ph->ms_eat) >= (long)(ph->pa->die))
// 		{
// 			pthread_mutex_unlock(&ph->pa->time_eat);
// 			pthread_mutex_lock(&ph->pa->write_mutex);
// 			ft_status("meurt\n", ph);
// 			pthread_mutex_unlock(&ph->pa->write_mutex);
// 			pthread_mutex_lock(&ph->pa->dead);
// 			ph->pa->stop = 1;
// 			pthread_mutex_unlock(&ph->pa->dead);
// 			return (NULL);
// 		}
// 		pthread_mutex_unlock(&ph->pa->time_eat);
// 	}
// 	return (NULL);
// }

void	*thread(void *data)
{
<<<<<<< HEAD
	t_phil	*phil;

	phil = (t_phil *)data;
	// if (phil->id % 2 == 0)
		// ft_usleep(phil->pa->eat / 10);
	if (phil->id % 2 == 0)
		usleep(2000);
		// ft_usleep(phil->pa->eat / 10);
	while (!ft_god_supervisor(phil, 0))
	{
		// pthread_create(&phil->thread_death_id, NULL, finishim, data);
		ft_operation(phil);
		// pthread_detach(phil->thread_death_id);
		pthread_mutex_lock(&phil->pa->finish);
		phil->nb_eat++;
		if (phil->nb_eat == (unsigned int)phil->pa->m_eat)
		{
			phil->finish = 1;
			phil->pa->nb_p_finish++;
			//
			// if (phil->nb_eat == (unsigned int)phil->pa->m_eat)
			if (phil->pa->nb_p_finish == phil->pa->total)
			{
				pthread_mutex_lock(&phil->pa->dead);
				phil->pa->stop = 2;
				pthread_mutex_unlock(&phil->pa->dead);
			}
		}
		pthread_mutex_unlock(&phil->pa->finish);
=======
t_phil					*ph;

	ph = (t_phil *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->pa->eat / 10);
	while (!ft_god_supervisor(ph, 0))
	{
		pthread_create(&ph->thread_death_id, NULL, finishim, data);
		ft_operation(ph);
		//pthread_detach(ph->thread_death_id);
		if ((int)++ph->nb_eat == ph->pa->m_eat)
		{
			pthread_mutex_lock(&ph->pa->finish);
			ph->finish = 1;
			ph->pa->nb_p_finish++;
			if (ph->pa->nb_p_finish == ph->pa->total)
			{
				pthread_mutex_unlock(&ph->pa->finish);
				ft_god_supervisor(ph, 2);
				pthread_mutex_unlock(&ph->pa->finish);
			}
			pthread_mutex_unlock(&ph->pa->finish);
			return (NULL);
		}
>>>>>>> 10e5ef6 (reglage time)
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
<<<<<<< HEAD
	finishim(&p->ph[0]);
=======
	finishim(&p->ph[i]);
>>>>>>> 10e5ef6 (reglage time)
	return (1);
}

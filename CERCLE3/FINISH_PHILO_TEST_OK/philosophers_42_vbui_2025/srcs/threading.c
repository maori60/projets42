/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/01/21 23:51:56 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier gère les threads des philosophes. Il inclut les fonctions pour :
** - Vérifier si un philosophe meurt (finishim).
** - Gérer les actions des philosophes dans les threads (thread).
** - Créer les threads pour chaque philosophe (threading).
*/

#include "../include/philosophers.h"


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
void	*thread(void *data)
{
t_phil					*ph;

	ph = (t_phil *)data;
	if (ph->pa->total == 1)
	{
		ft_status("has taken the fork of death\n", ph);
        ft_usleep(ph->pa->die); // Le philosophe attend jusqu'à son time_to_die
        ft_status("died\n", ph);
        ft_god_supervisor(ph, 1); // Arrêt global de la simulation
        return NULL;
	}

	if (ph->id % 2 == 0)
		ft_usleep(ph->pa->eat / 10);

		// pthread_create(&ph->thread_death_id, NULL, finishim, data);
	if (pthread_create(&ph->thread_death_id, NULL, finishim, data) != 0)
        {
            fprintf(stderr, "Error creating thread\n");
            ft_god_supervisor(ph, 1); // Arrêt global en cas d'erreur critique
            return (NULL);
        }
    pthread_detach(ph->thread_death_id); // Libère la mémoire du thread une fois terminé

	while (!ft_god_supervisor(ph, 0))
	{
			ft_operation(ph);
		//pthread_detach(ph->thread_death_id);
		if ((int)++ph->nb_eat == ph->pa->m_eat)
		{
			//pthread_mutex_lock(&ph->pa->finish);
			ph->finish = 1;
			ph->pa->nb_p_finish++;
			if (ph->pa->nb_p_finish == ph->pa->total)
			{
				pthread_mutex_lock(&ph->pa->finish);
				ft_god_supervisor(ph, 2);
				pthread_mutex_unlock(&ph->pa->finish);
			}
		// 	pthread_mutex_unlock(&ph->pa->finish);
		// 	return (NULL);
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
	// finishim(&p->ph[i]);
	return (1);
}
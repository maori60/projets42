/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:17 by vbui              #+#    #+#             */
/*   Updated: 2025/01/15 16:26:25 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient des fonctions utilitaires pour la gestion du temps,
** la vérification de la mort d'un philosophe et la gestion de la temporisation.
** Ces fonctions sont essentielles au fonctionnement du simulateur des philosophes.
*/

#include "../include/philosophers.h"

int	ft_god_supervisor(t_philo *ph, int i)
{
	pthread_mutex_lock(&ph->pa->dead);
	if (i)
		ph->pa->stop = i;
	if (ph->pa->stop)
	{
		pthread_mutex_unlock(&ph->pa->dead);
		return (1);
	}
	pthread_mutex_unlock(&ph->pa->dead);
	return (0);
}

long int	ft_timer(void)
{
	long int		time;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
	{
		perror("gettimeofday failed");
		exit(EXIT_FAILURE);
	}
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}




// long int	ft_timer(void)
// {
// 	long int		time;
// 	struct timeval	current_time;

// 	time = 0;
// 	if (gettimeofday(&current_time, NULL) == -1)
// 		ft_byebye("Gettimeofday returned -1\n");
// 	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
// 	return (time);
// }

// void	ft_usleep(long int time_in_ms)
// {
// 	long int	start_time;

// 	start_time = ft_timer();
// 	while ((ft_timer() - start_time) < time_in_ms)
// 		usleep(time_in_ms / 10);
// }

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;
	long int	end_time;
	long int	sleep_time;

	start_time = ft_timer();
	end_time = start_time + time_in_ms;
	while ((ft_timer() < end_time))
	{
		sleep_time = end_time - ft_timer();
		if (sleep_time > 10)
			usleep((sleep_time - 5) * 1000); // Réduit la charge CPU avec des tranches optimales
		else
			usleep(100); // Précision finale pour les petites durées restantes
	}
}

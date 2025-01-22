/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:17 by vbui              #+#    #+#             */
/*   Updated: 2025/01/22 09:06:20 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient des fonctions utilitaires pour la gestion du temps,
** la vérification de la mort d'un philosophe et la gestion de la temporisation.
** Ces fonctions sont essentielles au fonctionnement du simulateur des philosophes.
*/

#include "../include/philosophers.h"

int	ft_god_supervisor(t_phil *p, int i)
{

	pthread_mutex_lock(&p->pa->dead);
	if (i)
		p->pa->stop = i;
	if (p->pa->stop)
	{
		pthread_mutex_unlock(&p->pa->dead);
		return (1);
	}
	pthread_mutex_unlock(&p->pa->dead);
	return (0);

}



// long int	ft_timer(void)
// {
// 	long int		time;
// 	struct timeval	current_time;

// 	if (gettimeofday(&current_time, NULL) == -1)
// 	{
// 		perror("gettimeofday failed");
// 		exit(EXIT_FAILURE);
// 	}
// 	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
// 	return (time);
// }




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

// void	ft_usleep(long int time_in_ms)
// {
// 	long int	start_time;
// 	long int	end_time;
// 	long int	sleep_time;

// 	start_time = ft_timer();
// 	end_time = start_time + time_in_ms;
// 	while ((ft_timer() < end_time))
// 	{
// 		sleep_time = end_time - ft_timer();
// 		if (sleep_time > 10)
// 			usleep((sleep_time - 5) * 1000); // Réduit la charge CPU avec des tranches optimales
// 		else
// 			usleep(100); // Précision finale pour les petites durées restantes
// 	}
// }
// #define IS_OLD_PC 1 // Passez à 1 si l'ordinateur est ancien

// void	ft_usleep(long int time_in_ms)
// {
// 	long int	start_time;
// 	long int	end_time;
// 	long int	sleep_time;
// 	int			margin;

// 	start_time = ft_timer();
// 	end_time = start_time + time_in_ms;
// 	margin = IS_OLD_PC ? 200 : 1; // Ajustement de la marge pour une meilleure compatibilité

// 	(void)margin;
// 	(void)sleep_time;
// 	while ((ft_timer() < end_time))
// 	{
// 		sleep_time = end_time - ft_timer();
// 		if (sleep_time > margin)
// 			usleep((sleep_time - margin) * 1000); // Conversion correcte en microsecondes
// 		else
// 			usleep(5000); // Petits ajustements pour éviter des boucles trop rapides
// 	}
// }

long int	ft_timer(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_byebye("Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = ft_timer();
	while ((ft_timer() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}



// long int	ft_timer(void)
// {
// 	long int		time;
// 	struct timeval	current_time;

// 	if (gettimeofday(&current_time, NULL) == -1)
// 	{
// 		perror("gettimeofday failed");
// 		exit(EXIT_FAILURE);
// 	}
// 	time = (current_time.tv_sec * 1000)
// 		+ (current_time.tv_usec / 1000);
// 	return (time);
// }

// void	ft_usleep(long int time_in_ms)
// {
// 	long int	start_time;
// 	long int	end_time;
// 	long int	sleep_time;
// 	int			margin;

// 	start_time = ft_timer();
// 	end_time = start_time + time_in_ms;
// 	if (IS_OLD_PC)
// 		margin = 200;
// 	else
// 		margin = 1;
// 	while (ft_timer() < end_time)
// 	{
// 		sleep_time = end_time - ft_timer();
// 		if (sleep_time > margin)
// 			usleep((sleep_time - margin) * 1000);
// 		else
// 			usleep(USLEEP_TIMER);
// 	}
// }
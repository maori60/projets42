/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:19 by vbui              #+#    #+#             */
/*   Updated: 2025/01/15 20:56:55 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier gère les actions des philosophes : prendre des fourchettes,
** manger, dormir et penser. Il inclut également des fonctions pour afficher
** les statuts des philosophes avec une gestion des mutex pour éviter les
** conflits d'accès entre les threads.
*/

#include "../include/philosophers.h"

void	ft_status(char *str, t_philo *ph)
{
	long int	time;

	time = -1;
	time = ft_timer() - ph->pa->start_t;
	if (time >= 0 && time <= 2147483647 && !ft_god_supervisor(ph, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", ph->id, str);
	}
}

void	ft_sleep_and_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("dort\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->sleep);
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("pense\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
}

void	ft_operation(t_philo *ph)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (ph->pa->total == 1)
	{
		pthread_mutex_lock(&ph->left_f);
		pthread_mutex_lock(&ph->pa->write_mutex);
		ft_status("prend une fourchette\n", ph);
		pthread_mutex_unlock(&ph->pa->write_mutex);
		ft_usleep(ph->pa->die);
		pthread_mutex_lock(&ph->pa->write_mutex);
		ft_status("meurt\n", ph);
		pthread_mutex_unlock(&ph->pa->write_mutex);
		pthread_mutex_unlock(&ph->left_f);
		return ;
	}
	if (ph->id % 2 == 0)
	{
		first_fork = &ph->left_f;
		second_fork = ph->right_f;
	}
	else
	{
		first_fork = ph->right_f;
		second_fork = &ph->left_f;
	}
	pthread_mutex_lock(first_fork);
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("prend une fourchette\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_lock(second_fork);
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("prend une fourchette\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("mange\n", ph);
	pthread_mutex_lock(&ph->pa->time_eat);
	ph->ms_eat = ft_timer();
	pthread_mutex_unlock(&ph->pa->time_eat);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->eat);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
	ft_sleep_and_think(ph);
}
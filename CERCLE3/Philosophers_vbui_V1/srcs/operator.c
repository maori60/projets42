/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:19 by vbui              #+#    #+#             */
/*   Updated: 2025/01/14 20:55:56 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient les fonctions qui simulent les actions des philosophes :
** - `ft_status` : Affiche le statut d'un philosophe (ex. : "prend une fourchette", "mange").
** - `ft_sleep_and_think` : Gère les actions de dormir et penser d'un philosophe, en affichant les messages appropriés.
** - `ft_operation` : Gère les actions principales d'un philosophe (prendre des fourchettes, manger, dormir et penser).
*/

#include "../include/philosophers.h"

void	ft_status(char *str, t_philo *ph)
{
	long int		time;

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
	pthread_mutex_lock(&ph->left_f);
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("prend une fourchette\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	if (!ph->right_f)
	{
		ft_usleep(ph->pa->die * 2);
		return ;
	}
	pthread_mutex_lock(ph->right_f);
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
	pthread_mutex_unlock(ph->right_f);
	pthread_mutex_unlock(&ph->left_f);
	ft_sleep_and_think(ph);
}

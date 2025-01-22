/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:22:35 by vbui              #+#    #+#             */
/*   Updated: 2025/01/19 00:20:59 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_sleep_and_think(t_phil *ph)
{
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("sleep\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->sleep);
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("think\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
}

void	ft_operation_single_philo(t_phil *ph)
{
	pthread_mutex_lock(&ph->left_f);
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("take a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->die);
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("die\n", ph);
	ft_god_supervisor(ph, 1);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_unlock(&ph->left_f);
}

void	ft_take_forks(t_phil *ph, pthread_mutex_t *first_fork,
	pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(first_fork);
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("take a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_lock(second_fork);
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("take a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
}

void	ft_eat_and_release_forks(t_phil *ph, pthread_mutex_t *first_fork,
	pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(&ph->pa->write_mutex);
	ft_status("eating\n", ph);
	pthread_mutex_lock(&ph->pa->time_eat);
	ph->ms_eat = ft_timer();
	pthread_mutex_unlock(&ph->pa->time_eat);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->eat);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
	ft_sleep_and_think(ph);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:19 by vbui              #+#    #+#             */
/*   Updated: 2025/01/19 14:26:04 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_status(char *str, t_phil *ph)
{
	long int	time;

	time = ft_timer() - ph->pa->start_t;
	if (time >= 0 && time <= 2147483647 && !ft_god_supervisor(ph, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", ph->id, str);
		if (DEBUG && strcmp(str, "eating\n") == 0)
			printf("(count current meal: %d)", ph->nb_eat + 1);
		printf("\n");
	}
}

void	ft_operation_single(t_phil *ph)
{
	if (!pthread_mutex_trylock(&ph->left_f))
	{
		pthread_mutex_lock(&ph->pa->write_mutex);
		ft_status("take a fork\n", ph);
		pthread_mutex_unlock(&ph->pa->write_mutex);
		ft_usleep(ph->pa->die);
		pthread_mutex_lock(&ph->pa->write_mutex);
		ft_status("die\n", ph);
		pthread_mutex_unlock(&ph->pa->write_mutex);
		pthread_mutex_unlock(&ph->left_f);
	}
	else
		fprintf(stderr, "Error: Fork already locked for single philosopher\n");
	ft_god_supervisor(ph, 1);
}

void	ft_assign_forks(t_phil *ph, pthread_mutex_t **first,
	pthread_mutex_t **second)
{
	if (ph->id % 2 == 0)
	{
		*first = &ph->left_f;
		*second = ph->right_f;
	}
	else
	{
		*first = ph->right_f;
		*second = &ph->left_f;
	}
}

void	ft_operation(t_phil *ph)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (!ph || !ph->pa)
	{
		fprintf(stderr, "Error: Invalid philosopher or arguments\n");
		return ;
	}
	if (ph->pa->total == 1)
	{
		ft_operation_single(ph);
		return ;
	}
	ft_assign_forks(ph, &first_fork, &second_fork);
	if (!first_fork || !second_fork)
	{
		fprintf(stderr, "Error: Invalid fork pointers\n");
		return ;
	}
	ft_take_forks(ph, first_fork, second_fork);
	ft_eat_and_release_forks(ph, first_fork, second_fork);
}

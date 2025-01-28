/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:19 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 12:10:16 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
** ft_status:
** Prints the philosopher's status (time, id, message)
** if the simulation has not ended. Uses write_mutex to protect output.
*/
void	ft_status(char *str, t_phil *ph)
{
	long int	time;

	time = ft_timer() - ph->pa->start_t;
	pthread_mutex_lock(&ph->pa->write_mutex);
	if (!ft_god_supervisor(ph, 0))
	{
		printf("%ld Philo %d %s\n", time, ph->id, str);
	}
	pthread_mutex_unlock(&ph->pa->write_mutex);
}

/*
** ft_sleep_and_think:
** 1) Prints "is sleeping", sleeps for p->a.sleep ms.
** 2) Calculates time_to_think based on:
**    (die - (now - last_meal) - eat) / 2,
**    clamped between 1 and 200 ms.
** 3) Prints "is thinking" and sleeps for time_to_think ms.
*/
void	ft_sleep_and_think(t_phil *ph)
{
	long int	t_to_think;
	long int	now;

	pthread_mutex_lock(&ph->pa->write_mutex);
	if (!ft_god_supervisor(ph, 0))
		printf("%ld Philo %d is sleeping\n",
			ft_timer() - ph->pa->start_t, ph->id);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->sleep);
	pthread_mutex_lock(&ph->pa->time_eat);
	now = ft_timer();
	t_to_think = (ph->pa->die - (now - ph->ms_eat) - ph->pa->eat) / 2;
	pthread_mutex_unlock(&ph->pa->time_eat);
	if (t_to_think < 1)
		t_to_think = 1;
	if (t_to_think > 600)
		t_to_think = 200;
	pthread_mutex_lock(&ph->pa->write_mutex);
	if (!ft_god_supervisor(ph, 0))
		printf("%ld Philo %d is thinking\n",
			ft_timer() - ph->pa->start_t, ph->id);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(t_to_think);
}

/*
** ft_operation:
** 1) Picks forks in order (avoid deadlock):
**    - even id => left_f then right_f
**    - odd  id => right_f then left_f
** 2) Prints "has taken a fork" x2, updates last_meal, prints "is eating".
** 3) Frees forks and calls ft_sleep_and_think.
*/
void	ft_operation(t_phil *ph)
{
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;

	if (ph->id % 2 == 0)
	{
		fork1 = &ph->left_f;
		fork2 = ph->right_f;
	}
	else
	{
		fork1 = ph->right_f;
		fork2 = &ph->left_f;
	}
	pthread_mutex_lock(fork1);
	ft_status("has taken a fork", ph);
	pthread_mutex_lock(fork2);
	ft_status("has taken a fork", ph);
	pthread_mutex_lock(&ph->meal_time_lock);
	ph->ms_eat = ft_timer();
	pthread_mutex_unlock(&ph->meal_time_lock);
	ft_status("is eating", ph);
	ft_usleep(ph->pa->eat);
	pthread_mutex_unlock(fork2);
	pthread_mutex_unlock(fork1);
	ft_sleep_and_think(ph);
}

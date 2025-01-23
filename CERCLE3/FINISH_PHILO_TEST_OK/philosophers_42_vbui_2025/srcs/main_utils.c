/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:46:17 by vbui              #+#    #+#             */
/*   Updated: 2025/01/23 03:37:19 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
** ft_god_supervisor:
** Locks the 'dead' mutex (pa->stop).
** If i != 0, sets stop = i (1 = died, 2 = all have eaten).
** Returns 1 if simulation must stop, 0 otherwise.
*/
int	ft_god_supervisor(t_phil *p, int i)
{
	pthread_mutex_lock(&p->pa->dead);
	if (i != 0)
		p->pa->stop = i;
	if (p->pa->stop != 0)
	{
		pthread_mutex_unlock(&p->pa->dead);
		return (1);
	}
	pthread_mutex_unlock(&p->pa->dead);
	return (0);
}

/*
** ft_timer:
** Returns the current time in milliseconds.
*/
long int	ft_timer(void)
{
	long int		time;
	struct timeval	current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
	{
		ft_putstr_fd("Error: gettimeofday returned -1\n", 2);
		exit(EXIT_FAILURE);
	}
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

/*
** ft_usleep:
** Sleeps for 'time_in_ms' ms in small increments,
** regularly checking if we've reached the target time.
*/
void	ft_usleep(long int time_in_ms)
{
	long int	end;
	long int	now;

	end = ft_timer() + time_in_ms;
	now = ft_timer();
	while (now < end)
	{
		usleep(500);
		now = ft_timer();
	}
}

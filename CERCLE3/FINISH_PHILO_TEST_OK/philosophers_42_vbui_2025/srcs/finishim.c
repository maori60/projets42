/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/01/23 04:03:48 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
** finishim:
** Monitors one philosopher. 
** While sim not stopped, checks if time since last meal > time_to_die.
** If so => prints "died", sets stop=1.
*/
void	*finishim(void *data)
{
	t_phil	*ph;

	ph = (t_phil *)data;
	if (ph == NULL || ph->pa == NULL)
		return ((void *)0);
	while (!ft_god_supervisor(ph, 0))
	{
		pthread_mutex_lock(&ph->meal_time_lock);
		if (!ph->finish && (ft_timer() - ph->ms_eat) >= ph->pa->die)
		{
			pthread_mutex_unlock(&ph->meal_time_lock);
			ft_status("died", ph);
			ft_god_supervisor(ph, 1);
			return ((void *)0);
		}
		pthread_mutex_unlock(&ph->meal_time_lock);
		usleep(1000);
	}
	return ((void *)0);
}

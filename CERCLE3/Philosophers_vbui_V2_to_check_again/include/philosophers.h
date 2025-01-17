/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:56:50 by vbui              #+#    #+#             */
/*   Updated: 2025/01/15 22:03:52 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient les définitions des structures et les prototypes
** des fonctions utilisées dans le projet Philosopher.
**
** MUTEX :
** - `write_mutex` : Synchronise l'affichage des messages des philosophes.
** - `dead` : Protège l'accès à l'indicateur `stop` (arrêt de la simulation).
** - `time_eat` : Protège l'accès au temps du dernier repas des philosophes.
** - `finish` : Protège le compteur des philosophes ayant terminé de manger.
** - Chaque philosophe possède un mutex pour sa fourchette gauche (`left_f`).
**
** NOMBRE TOTAL DE MUTEX :
** - 4 mutex globaux (`t_arg`).
** - 1 mutex par philosophe (fourchette).
** - Total : 4 + nombre de philosophes.
*/

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

/*
** `t_arg` : Structure contenant les paramètres de la simulation.
*/
typedef struct s_arg
{
	int						total;
	int						die;
	int						eat;
	int						sleep;
	int						m_eat;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
	int						nb_p_finish;
	int						stop;
}							t_arg;

/*
** `t_philo` : Structure contenant les informations spécifiques à chaque philosophe.
*/
typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*right_f;
	pthread_mutex_t			left_f;
	t_arg					*pa;
	long int				ms_eat;
	unsigned int			nb_eat;
	int						finish;
}							t_philo;

/*
** `t_p` : Structure regroupant l'ensemble des philosophes et des paramètres globaux.
*/
typedef struct s_p
{
	t_philo					*ph;
	t_arg					a;
}							t_p;

/*
** Prototypes des fonctions.
*/
int				parsing_args(int argc, char **argv, t_p *p);
int				ft_initialization(t_p *p);
int				ft_byebye(char *str);
void			ft_status(char *str, t_philo *ph);
long int		ft_timer(void);
void			ft_putstr_fd(char *s, int fd);
void			ft_usleep(long int time_in_ms);
int				threading(t_p *p);
void			ft_operation(t_philo *ph);
int				ft_god_supervisor(t_philo *ph, int i);
int				ft_strlen(char *str);
void			ft_sleep_and_think(t_philo *ph);

#endif

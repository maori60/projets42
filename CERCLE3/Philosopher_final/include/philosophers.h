/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:56:50 by vbui              #+#    #+#             */
/*   Updated: 2025/01/19 14:28:02 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient les définitions des structures et les prototypes
** des fonctions utilisées dans le projet Philosopher.
*/

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define DEBUG 0
# define MAX_PHILOS 200
# define IS_OLD_PC 0

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

/*
** `t_arg` : Structure contenant les paramètres de la simulation.
*/
typedef struct s_arg
{
	int				total;
	int				die;
	int				eat;
	int				sleep;
	int				m_eat;
	long int		start_t;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead;
	pthread_mutex_t	time_eat;
	pthread_mutex_t	finish;
	int				nb_p_finish;
	int				stop;
}					t_arg;

/*
** `t_phil` : Structure contenant les informations spécifiques à chaque
** philosophe.
*/
typedef struct s_phil
{
	int				id;
	pthread_t		thread_id;
	pthread_t		thread_death_id;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	left_f;
	t_arg			*pa;
	long int		ms_eat;
	unsigned int	nb_eat;
	int				finish;
}					t_phil;

/*
** `t_p` : Structure regroupant l'ensemble des philosophes et des paramètres
** globaux.
*/
typedef struct s_p
{
	t_phil			*ph;
	t_arg			a;
}					t_p;

/*
** Prototypes des fonctions.
*/
int			parsing_args(int argc, char **argv, t_p *p);
int			ft_initialization(t_p *p);
int			ft_byebye(char *str);
void		ft_status(char *str, t_phil *ph);
long int	ft_timer(void);
void		ft_putstr_fd(char *s, int fd);
void		ft_usleep(long int time_in_ms);
int			threading(t_p *p);
void		ft_operation(t_phil *ph);
int			ft_god_supervisor(t_phil *ph, int i);
int			ft_strlen(char *str);
void		ft_sleep_and_think(t_phil *ph);
int			ft_isdigit(int c);
long		ft_atol(const char *str);
int			ft_numerik(char **argv, int j);
void		ft_operation_single_philo(t_phil *ph);
void		ft_take_forks(t_phil *ph, pthread_mutex_t *first_fork,
				pthread_mutex_t *second_fork);
void		ft_eat_and_release_forks(t_phil *ph, pthread_mutex_t *first_fork,
				pthread_mutex_t *second_fork);

#endif

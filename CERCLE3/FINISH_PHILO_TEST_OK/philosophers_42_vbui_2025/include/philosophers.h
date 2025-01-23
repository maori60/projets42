/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:56:50 by vbui              #+#    #+#             */
/*   Updated: 2025/01/23 05:11:54 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define DEBUG 0
# define MAX_PHILO 

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

/*
** t_arg:
**  - total: nombre total de philosophes
**  - die: temps avant de mourir
**  - eat: temps pour manger
**  - sleep: temps pour dormir
**  - m_eat: nombre de repas requis (ou -1 si non spécifié)
**  - start_t: temps de démarrage (ms)
**  - write_mutex, dead, time_eat, finish: mutex globaux
**  - stop: indicateur d'arrêt (0=continue,1=mort,2=tous ont mangé)
**  - nb_p_finish: nb de philosophes ayant atteint m_eat
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
}	t_arg;

/*
** t_phil:
**  - id: Identifiant du philo
**  - thread_id: thread principal
**  - thread_death_id: thread "finishim"
**  - right_f: pointeur vers le mutex de la fourchette droite
**  - left_f: mutex de la fourchette gauche
**  - pa: pointeur vers struct globale t_arg
**  - ms_eat: dernier repas (ms)
**  - nb_eat: nb de repas pris
**  - finish: indique si m_eat atteint
**  - meal_time_lock: mutex perso pour last_meal/nb_eat
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
	pthread_mutex_t	meal_time_lock;
}	t_phil;

/*
** t_p: regroupe t_phil* et t_arg
*/
typedef struct s_p
{
	t_phil	*ph;
	t_arg	a;
}	t_p;

/* Prototypes */
int			parsing_args(int argc, char **argv, t_p *p);
int			ft_initialization(t_p *p);
int			ft_byebye(char *str);
void		ft_status(char *str, t_phil *ph);
long int	ft_timer(void);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(long int ln, int fd);
void		ft_usleep(long int time_in_ms);
int			threading(t_p *p);
void		ft_operation(t_phil *ph);
int			ft_god_supervisor(t_phil *ph, int i);
int			ft_strlen(char *str);
void		ft_sleep_and_think(t_phil *ph);
int			ft_numerik(char **argv, int j);
int			ft_atoi(const char *str);
int			main(int argc, char **argv);
void		*finishim(void *data);
void		*thread(void *data);
void		stop_operator(t_p *p);
int			ft_who_is_died(t_p *p);

#endif

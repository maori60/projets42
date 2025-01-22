/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:56:50 by vbui              #+#    #+#             */
/*   Updated: 2025/01/14 20:58:49 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ce fichier contient les déclarations des structures et des prototypes de
** fonctions utilisés pour simuler le problème des philosophes.
**
** - `t_arg` : Structure qui contient les paramètres globaux de la simulation
**   (nombre de philosophes, temps de vie, temps de repas, etc.).
** - `t_philo` : Structure qui contient les informations spécifiques à chaque philosophe
**   (identifiant, nombre de repas, état de la simulation, etc.).
** - `t_p` : Structure qui regroupe l'ensemble des philosophes et les paramètres de la simulation.
**
** Les fonctions définies dans ce fichier servent à :
** - Gérer l'initialisation des paramètres et des philosophes.
** - Gérer l'exécution des philosophes (manger, dormir, penser).
** - Assurer la synchronisation avec des mutex pour éviter les conditions de course.
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
** Cette structure est utilisée pour stocker les informations globales telles que :
** - le nombre total de philosophes
** - le temps de vie avant la mort (die)
** - le temps de repas (eat)
** - le temps de sommeil (sleep)
** - le nombre de repas qu'un philosophe doit faire (m_eat)
** - les mutex nécessaires pour la synchronisation des actions des philosophes
*/
typedef struct s_arg
{
	int						total;			// Nombre total de philosophes
	int						die;			// Temps maximum avant qu'un philosophe meurt de faim
	int						eat;			// Temps qu'un philosophe prend pour manger
	int						sleep;			// Temps qu'un philosophe passe à dormir
	int						m_eat;			// Nombre de repas que chaque philosophe doit prendre avant la fin
	long int				start_t;		// Heure de début de la simulation
	pthread_mutex_t			write_mutex;	// Mutex pour la synchronisation de l'écriture
	pthread_mutex_t			dead;			// Mutex pour vérifier si la simulation doit être arrêtée
	pthread_mutex_t			time_eat;		// Mutex pour la gestion du temps de repas
	pthread_mutex_t			finish;			// Mutex pour signaler la fin de la simulation
	int						nb_p_finish;	// Nombre de philosophes ayant fini de manger
	int						stop;			// Indicateur pour stopper la simulation
}							t_arg;

/*
** `t_philo` : Structure contenant les informations spécifiques à chaque philosophe.
** Chaque philosophe est représenté par un thread, et chaque philosophe possède des informations
** telles que son identifiant, le nombre de repas qu'il a pris, l'état de sa simulation, et les fourchettes qu'il utilise.
** Elle contient aussi un pointeur vers les paramètres globaux de la simulation.
*/
typedef struct s_philo
{
	int						id;				// Identifiant unique du philosophe
	pthread_t				thread_id;		// Identifiant du thread du philosophe
	pthread_t				thread_death_id; // Identifiant du thread de gestion de la mort
	pthread_mutex_t			*right_f;		// Pointeur vers la fourchette de droite
	pthread_mutex_t			left_f;			// Fourchette de gauche
	t_arg					*pa;			 // Pointeur vers les paramètres globaux
	long int				ms_eat;			// Temps du dernier repas du philosophe
	unsigned int			nb_eat;			// Nombre de repas pris par le philosophe
	int						finish;			// Indicateur de fin pour ce philosophe
}							t_philo;

/*
** `t_p` : Structure regroupant l'ensemble des philosophes (`ph`) et les paramètres globaux de la simulation (`a`).
** Elle sert à stocker les informations nécessaires pour l'exécution de la simulation.
*/
typedef struct s_p
{
	t_philo					*ph;			// Tableau des philosophes
	t_arg					a;				// Paramètres de la simulation
}							t_p;


/*
** Prototypes des fonctions utilisées pour gérer la simulation des philosophes.
** Ces fonctions sont responsables de la gestion des arguments, de l'initialisation des données,
** de l'exécution des actions des philosophes (manger, dormir, penser), et de la synchronisation avec des mutex.
*/
int				parse_args(int argc, char **argv, t_p *p);
int				initialize(t_p *p);
int				ft_byebye(char *str);
void			ft_status(char *str, t_philo *ph);
long int		ft_timer(void);
void			ft_putstr_fd(char *s, int fd);
void			ft_usleep(long int time_in_ms);
int				threading(t_p *p);
void			ft_operation(t_philo *ph);
int				ft_god_supervisor(t_philo *ph, int i);
int				ft_strlen(char *str);

#endif

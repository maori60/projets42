// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/14 20:51:23 by vbui              #+#    #+#             */
// /*   Updated: 2025/01/15 14:53:25 by vbui             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// /*
// ** Ce fichier contient la fonction principale qui initialise le programme
// ** et gère l'exécution des philosophes. Les principales fonctions sont :
// ** - `ft_byebye` : Affiche un message d'erreur et termine le programme.
// ** - `ft_who_is_died` : Vérifie si la simulation doit être arrêtée en raison de la mort d'un philosophe.
// ** - `stop_operator` : Arrête la simulation en libérant les ressources, détruisant les mutex et affichant un message de fin.
// ** - `main` : Fonction principale qui parse les arguments, initialise les données,
// **   crée les threads des philosophes et gère leur exécution.
// */

// #include "../include/philosophers.h"

// int	ft_byebye(char *str)
// {
// 	ft_putstr_fd("Error : ", 2);
// 	ft_putstr_fd(str, 2);
// 	return (0);
// }

// int	ft_who_is_died(t_p *p)
// {
// 	pthread_mutex_lock(&p->a.dead);
// 	if (p->a.stop)
// 	{
// 		pthread_mutex_unlock(&p->a.dead);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&p->a.dead);
// 	return (0);
// }

// void	stop_operator(t_p *p)
// {
// 	int	i;

// 	i = -1;
// 	while (!ft_who_is_died(p))
// 		ft_usleep(1);
// 	while (++i < p->a.total)
// 		pthread_join(p->ph[i].thread_id, NULL);
// 	pthread_mutex_destroy(&p->a.write_mutex);
// 	i = -1;
// 	while (++i < p->a.total)
// 		pthread_mutex_destroy(&p->ph[i].left_f);
// 	if (p->a.stop == 2)
// 		printf("chaque philosophe a mangé %d fois\n", p->a.m_eat);
// 	free(p->ph);
// }

// int	main(int argc, char **argv)
// {
// 	t_p		p;

// 	if (!(parsing_args(argc, argv, &p)))
// 		return (ft_byebye("wesh rentre les bons arguments\n"));
// 	p.ph = malloc(sizeof(t_philo) * p.a.total);
// 	if (!p.ph)
// 		return (ft_byebye("Malloc returned NULL\n"));
// 	if (!ft_initialization(&p) || !threading(&p))
// 	{
// 		free(p.ph);
// 		return (0);
// 	}
// 	stop_operator(&p);
// }


#include "../include/philosophers.h"

int	ft_byebye(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	ft_who_is_died(t_p *p)
{
	pthread_mutex_lock(&p->a.dead);
	if (p->a.stop)
	{
		pthread_mutex_unlock(&p->a.dead);
		return (1);
	}
	pthread_mutex_unlock(&p->a.dead);
	return (0);
}

// void	stop_operator(t_p *p)
// {
// 	int	i;
// 	i = 0;
// 	while (!ft_who_is_died(p))
// 		ft_usleep(1);
// 	while (i < p->a.total)
// 	{
// 		pthread_join(p->ph[i].thread_id, NULL);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&p->a.write_mutex);
// 	i = 0;
// 	while (i < p->a.total)
// 	{
// 		pthread_mutex_destroy(&p->ph[i].left_f);
// 		i++;
// 	}
// 	pthread_mutex_lock(&p->a.dead); // je dois lock ici 
// 	if (p->a.stop == 2)
// 		printf("Chaque philosophe mange %d fois\n", p->a.m_eat);
// 	pthread_mutex_unlock(&p->a.dead); // unlock ici 
// 	free(p->ph);
// }

void	stop_operator(t_p *p)
{
	int	i;

	i = 0;
	while (!ft_who_is_died(p)) // Attendre que l'arrêt soit déclenché
		ft_usleep(1);
	while (i < p->a.total)
	{
		pthread_join(p->ph[i].thread_id, NULL);
		i++;
	}
	pthread_mutex_destroy(&p->a.write_mutex);
	i = 0;
	while (i < p->a.total)
	{
		pthread_mutex_destroy(&p->ph[i].left_f);
		i++;
	}

	pthread_mutex_lock(&p->a.dead);
	if (p->a.stop == 2)
		printf("Chaque philosophe mange %d fois\n", p->a.m_eat);
	pthread_mutex_unlock(&p->a.dead);

	free(p->ph);
}


int	main(int argc, char **argv)
{
	t_p	p;

	if (!(parsing_args(argc, argv, &p)))
		return (ft_byebye("Invalid arguments\n"));
	p.ph = malloc(sizeof(t_phil) * p.a.total);
	if (!p.ph)
		return (ft_byebye("Malloc returned NULL\n"));
	if (!ft_initialization(&p) || !threading(&p))
	{
		free(p.ph);
		return (0);
	}
	stop_operator(&p);
}


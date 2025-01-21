/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:31:51 by vbui              #+#    #+#             */
/*   Updated: 2024/06/10 16:45:46 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* free_stack:
Libère chaque élément d'une pile donnée et initialise le pointeur de pile à NULL.
*/
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/* exit_error:
    Écrit "Error\n" sur la sortie standard après avoir libéré les piles a et b.
    Quitte avec le code d'erreur standard 1.
*/
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/* ft_atoi:
Convertit une chaîne de caractères alphanumérique en un long int
*/
long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

/* ft_putstr:
    Affiche une chaîne de caractères donnée sur la sortie standard.
*/
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* nb_abs:
    Retourne la valeur absolue d'un nombre donné.
    La valeur absolue d'un nombre est utilisée pour mesurer la distance
	 de ce nombre par rapport à 0, qu'il soit positif ou négatif 
	 (la valeur absolue de -6 est 6).
*/
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

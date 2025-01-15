/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:31:06 by vbui              #+#    #+#             */
/*   Updated: 2024/06/10 16:46:18 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_sorted:
* Vérifie si une pile est triée.
* Retourne 0 si la pile n'est pas triée, 1 si elle est triée.
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
* Choisit une méthode de tri en fonction du nombre
* de valeurs à trier.
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

/* main:
* Vérifie si l'entrée est correcte, auquel cas il initialise les piles a et b,
* attribue des indices à chaque valeur et trie les piles.
 Une fois le tri terminé, libère
* les piles et quitte le programme.
*/
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (ac == 2 && av[1][0])
	{
		av = ft_split(av[1], ' ');
		if (!is_correct_input_one_arg(av))
			(free_tab(av), exit_error(NULL, NULL));
		stack_a = fill_stack_values_one_arg(ac, av);
	}
	else if (!av[1][0] || !is_correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	if (ac > 2)
		stack_a = fill_stack_values(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	(free_stack(&stack_a), free_stack(&stack_b));
	if (ac == 2)
		free_tab(av);
	return (0);
}

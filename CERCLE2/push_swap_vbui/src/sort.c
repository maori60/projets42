/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:31:37 by vbui              #+#    #+#             */
/*   Updated: 2024/06/10 16:46:27 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_all_save_three:
    Pousse tous les éléments de la pile a dans la pile b, sauf les
	 trois derniers.
    Pousse d'abord les valeurs les plus petites, puis les valeurs les plus 
	grandes pour aider à l'efficacité du tri.
*/
static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

/* shift_stack:
Après que la majeure partie de la pile soit triée, déplace la pile a jusqu'à 
ce que la valeur la plus basse soit au sommet. Si elle se trouve dans la
 moitié inférieure de la pile, effectue une rotation inversée pour la
  mettre en position, sinon, effectue une rotation jusqu'à ce qu'elle 
  soit au sommet de la pile.
*/
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

/* sort:
Algorithme de tri pour une pile de plus de 3 éléments.
Pousse tout sauf 3 nombres dans la pile B.
Trie les 3 nombres restants dans la pile A.
Calcule le mouvement le plus rentable.
Déplace les éléments jusqu'à ce que la pile A soit ordonnée.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}

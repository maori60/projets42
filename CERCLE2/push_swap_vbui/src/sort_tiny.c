/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:31:32 by vbui              #+#    #+#             */
/*   Updated: 2024/06/10 16:46:25 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find_highest_index:
    Retourne l'index le plus élevé dans une pile.
*/
static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* tiny_sort:
Trie une pile de 3 nombres en 2 mouvements ou moins. Le tri se fait par index 
plutôt que par valeur. 
Exemple :
valeurs :     0   9   2
index :     [1] [3] [2]
Solution, 2 mouvements :
rra : 
valeurs :     2   0   9
index :     [2] [1] [3]
sa :
valeurs :     0   2   9
index :     [1] [2] [3]
*/
void	tiny_sort(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:31:46 by vbui              #+#    #+#             */
/*   Updated: 2024/06/10 16:46:30 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap:
    Échange les 2 éléments du sommet d'une pile.
    Ne fait rien s'il y a un seul élément ou aucun.
*/
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* do_sa:
    Échange les 2 éléments du sommet de la pile a.
    Affiche "sa" sur la sortie standard.
*/
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* do_sb:
    Échange les 2 éléments du sommet de la pile b.
    Affiche "sb" sur la sortie standard.
*/
void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* do_ss:
    Échange les 2 éléments du sommet de la pile a et les
	 2 éléments du sommet de la pile b.
    Affiche "ss" sur la sortie standard.
*/
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}

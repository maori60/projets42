/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:31:18 by vbui              #+#    #+#             */
/*   Updated: 2024/06/10 16:46:20 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push:
    Pousse l'élément du sommet de la pile src vers le sommet de la pile dest.
*/
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

/* do_pa:
    Pousse l'élément du sommet de la pile b vers le sommet de la pile a.
    Affiche "pa" sur la sortie standard.
*/
void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

/* do_pb:
    Pousse l'élément du sommet de la pile a vers le sommet de la pile b.
    Affiche "pb" sur la sortie standard.
*/
void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

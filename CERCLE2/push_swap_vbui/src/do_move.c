/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:30:38 by vbui              #+#    #+#             */
/*   Updated: 2024/06/10 16:46:08 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* do_rev_rotate_both:
* Effectue une rotation inversée des piles A et B jusqu'à ce que l'une 
d'elles soit en position.
* Le coût indiqué est négatif puisque les deux positions sont 
dans la moitié inférieure de leurs piles respectives. Le coût augmente 
à mesure que les piles sont
* tournées, et quand l'une atteint 0, la pile a été tournée autant que possible
* et la position supérieure est correcte.
*/
static void	do_rev_rotate_both(t_stack **a, t_stack **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/* do_rotate_both:
* Effectue une rotation des piles A et B jusqu'à ce que l'une d'elles 
soit en position.
* Le coût indiqué est positif puisque les deux positions sont dans
 la moitié supérieure de leurs piles respectives. Le coût diminue 
 à mesure que les piles sont
* tournées, et quand l'une atteint 0, la pile a été tournée autant que possible
* et la position supérieure est correcte.
*/
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/* do_rotate_a:
* Fait tourner la pile A jusqu'à ce qu'elle soit en position. 
Si le coût est négatif,
* la pile sera tournée en sens inverse, si le coût est positif, elle sera
* tournée.
*/
static void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

/* do_rotate_b:
* Fait tourner la pile B jusqu'à ce qu'elle soit en position. 
Si le coût est négatif,
* la pile sera tournée en sens inverse, si le coût est
 positif, elle sera tournée.
*/
static void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

/* do_move:
* Choix du mouvement à effectuer pour amener l'élément de la pile B 
à la position correcte dans la pile A.
* Si les coûts de déplacement des piles A et B en position 
correspondent (c'est-à-dire tous les deux négatifs ou tous les 
deux positifs), les deux seront tournés ou tournés en sens 
inverse en même temps.
* Ils pourraient également être tournés séparément, avant 
de finalement pousser l'élément supérieur de la pile B vers le haut de la pile A.
*/
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}

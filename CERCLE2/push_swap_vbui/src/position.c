/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:31:11 by vbui              #+#    #+#             */
/*   Updated: 2024/06/10 16:46:19 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_position:
Assigne une position à chaque élément d'une pile de haut en bas
dans l'ordre croissant.
Exemple de pile :
valeur :     3   0   9   1
index :     [3] [1] [4] [2]
position :  <0> <1> <2> <3>
Ceci est utilisé pour calculer le coût de déplacement d'un certain nombre 
à une certaine position. Si l'exemple ci-dessus est la pile b, cela 
ne coûterait rien (0) de pousser le premier élément dans la pile a. 
Cependant, si nous voulons pousser la valeur la plus élevée, 9, qui 
est en troisième position, cela coûterait 2 mouvements supplémentaires 
pour amener ce 9 en haut de b avant de le pousser dans la pile a.
*/
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* get_lowest_index_position:
Obtient la position actuelle de l'élément avec l'index le plus bas dans une pile.
*/
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_target:
Choisit la meilleure position cible dans la pile A pour l'index donné 
d'un élément dans la pile B. Commence par vérifier si l'index de 
l'élément de B peut être placé quelque part entre les éléments de la 
pile A, en vérifiant s'il y a un élément dans la pile A avec un index
 plus grand. Si ce n'est pas le cas, il trouve l'élément avec l'index 
 le plus petit dans A et assigne cela comme position cible.
 --- Exemple :
 target_pos commence à INT_MAX
Index de B : 3
A contient les index : 9 4 2 1 0
9 > 3 && 9 < INT_MAX  : target_pos mis à jour à 9
4 > 3 && 4 < 9        : target_pos mis à jour à 4
2 < 3 && 2 < 4        : pas de mise à jour !
La position cible doit donc être celle de l'index 4, 
car c'est l'index le plus proche.
--- Exemple :
target_pos commence à INT_MAX
Index de B : 20
A contient les index : 16 4 3
16 < 20               : pas de mise à jour ! target_pos = INT_MAX
4  < 20               : pas de mise à jour ! target_pos = INT_MAX
3  < 20               : pas de mise à jour ! target_pos = INT_MAX
... target_pos reste à INT_MAX, il faut changer de stratégie.
16 < 20               : target_pos mis à jour à 20
4  < 20               : target_pos mis à jour à 4
3  < 20               : target_pos mis à jour à 3
La position cible doit donc être celle de l'index 3, car 
c'est la "fin" de la pile.
*/
static int	get_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* get_target_position:
Assigne une position cible dans la pile A à chaque élément de la pile B.
La position cible est l'endroit où l'élément dans B doit se rendre
pour être trié correctement. Cette position sera utilisée pour calculer
le coût de déplacement de chaque élément vers sa position cible dans la pile A.
*/
void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

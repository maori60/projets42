/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:59:33 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 15:08:51 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	swap(t_env	*ptr1)
{
	char	*temp_name;
	char	*temp_value;

	temp_name = ptr1->name;
	temp_value = ptr1->value;
	ptr1->name = ptr1->next->name;
	ptr1->value = ptr1->next->value;
	ptr1->next->name = temp_name;
	ptr1->next->value = temp_value;
	return (1);
}

void	bubble_sort_list(t_env *head)
{
	int		swapped;
	t_env	*ptr1;
	t_env	*lptr;

	lptr = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = head;
		while (ptr1->next != lptr)
		{
			if (ft_strcmp(ptr1->name, ptr1->next->name) > 0)
				swapped = swap(ptr1);
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

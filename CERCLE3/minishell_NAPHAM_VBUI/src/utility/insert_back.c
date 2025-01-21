/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:44:21 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 22:44:43 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_back(t_arg_list *head, char *arg)
{
	t_arg_list	*new_node;
	t_arg_list	*last;

	if (arg == NULL)
		return ;
	if (head->arg == NULL)
	{
		head->arg = arg;
		head->next = NULL;
		return ;
	}
	new_node = (t_arg_list *)malloc(sizeof(t_arg_list));
	new_node->arg = arg;
	new_node->next = NULL;
	if (head->next == NULL)
	{
		head->next = new_node;
		return ;
	}
	last = head->next;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:33:49 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 15:08:52 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	list_size(t_arg_list *head)
{
	t_arg_list	*current;
	int			i;

	current = head;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

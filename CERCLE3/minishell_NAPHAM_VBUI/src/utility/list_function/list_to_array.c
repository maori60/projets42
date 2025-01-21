/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:45:24 by napham            #+#    #+#             */
/*   Updated: 2024/12/20 20:46:56 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_array(t_arg_list *head)
{
	t_arg_list	*current;
	char		**new_str;
	int			len;

	if (!head)
		return (NULL);
	current = head;
	len = list_size(head);
	new_str = (char **)malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (current != NULL)
	{
		new_str[len] = current->arg;
		current = current->next;
		len++;
	}
	new_str[len] = (char *) NULL;
	return (new_str);
}

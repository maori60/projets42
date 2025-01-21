/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_free_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:13:31 by napham            #+#    #+#             */
/*   Updated: 2024/12/20 20:43:42 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	t_free_list(t_arg_list *head, bool arg_reused)
{
	t_arg_list	*tmp;

	while (head != NULL)
	{
		tmp = head->next;
		if (arg_reused == false)
			free(head->arg);
		free(head);
		head = tmp;
	}
}

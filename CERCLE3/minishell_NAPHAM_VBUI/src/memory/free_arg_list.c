/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arg_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:13:14 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 10:18:43 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arg_list(t_arg_list *arg_list)
{
	t_arg_list	*temp;

	while (arg_list != NULL)
	{
		if (arg_list->arg != NULL)
			free(arg_list->arg);
		temp = arg_list->next;
		free(arg_list);
		arg_list = temp;
	}
}

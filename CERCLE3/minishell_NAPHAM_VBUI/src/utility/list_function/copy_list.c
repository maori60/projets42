/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:58:34 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 15:08:51 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*copy_list(t_env *head)
{
	t_env	*new;

	if (head == NULL)
		return (NULL);
	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = ft_strdup(head->name);
	new->value = ft_strdup(head->value);
	new->next = copy_list(head->next);
	return (new);
}

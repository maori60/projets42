/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:28:24 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 16:29:32 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_env(char *name, char *value, t_shell *shell)
{
	t_env	*tmp;

	tmp = find_env(name, shell->envs);
	if (tmp)
	{
		free(tmp->value);
		tmp->value = ft_strdup(value);
		if (!tmp->value)
			return (0);
	}
	return (1);
}

int	add_env(char *name, char *value, t_shell *shell)
{
	t_env	*new;
	t_env	*tmp;

	tmp = find_env(name, shell->envs);
	if (tmp)
		return (update_env(name, value, shell));
	new = malloc(sizeof(t_env));
	if (!new)
		return (1);
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	new->next = NULL;
	if (shell->envs->size == 0)
	{
		shell->envs->head = new;
		shell->envs->tail = shell->envs->head;
	}
	else
	{
		shell->envs->tail->next = new;
		shell->envs->tail = new;
	}
	shell->envs->size++;
	return (0);
}

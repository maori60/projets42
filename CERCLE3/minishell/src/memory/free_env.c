/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:54:48 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 15:08:51 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	delete_head(t_shell *shell)
{
	t_env	*tmp;

	if (shell->envs->head == NULL)
		return (0);
	tmp = shell->envs->head;
	shell->envs->head = shell->envs->head->next;
	if (tmp == shell->envs->tail)
		shell->envs->tail = shell->envs->head;
	free_node(tmp);
	return (0);
}

static int	delete_tail(t_shell *shell)
{
	t_env	*tmp;

	if (shell->envs->head == NULL)
		return (0);
	if (shell->envs->head->next == NULL)
		return (delete_head(shell));
	tmp = shell->envs->head;
	while (tmp->next != shell->envs->tail)
		tmp = tmp->next;
	shell->envs->tail = tmp;
	tmp = tmp->next;
	shell->envs->tail->next = NULL;
	return (free_node(tmp));
}

int	del_node(t_env *del, t_shell *shell)
{
	t_env	*tmp;
	t_env	*current;

	if (!shell->envs->head)
		return (0);
	if (shell->envs->head == del)
		return (delete_head(shell));
	if (shell->envs->tail == del)
		return (delete_tail(shell));
	current = shell->envs->head;
	while (current->next)
	{
		if (current->next == del)
		{
			tmp = current->next;
			current->next = current->next->next;
			return (free_node(tmp));
		}
		current = current->next;
	}
	return (0);
}

int	free_list(t_env *head)
{
	t_env	*rmv;
	t_env	*next;

	rmv = head;
	while (rmv)
	{
		next = rmv->next;
		free_node(rmv);
		rmv = next;
	}
	return (-1);
}

int	free_env(t_shell *shell)
{
	if (shell->envs->size > 0)
		free_list(shell->envs->head);
	free(shell->envs);
	return (-1);
}

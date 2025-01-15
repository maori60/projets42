/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:15:26 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 10:13:51 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int	ft_write_env(t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->envs->head;
	while (tmp)
	{
		if (secure_write_fd(1, tmp->name) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (secure_write_fd(1, "=") == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (secure_write_fd(1, tmp->value) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (secure_write_fd(1, "\n") == EXIT_FAILURE)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

int	ft_env(t_exec_cmd *exec_cmd, t_shell *shell)
{
	pid_t	pid;
	int		exit_status;

	pid = fork_call();
	if (pid == 0)
	{
		if (run_cmd((t_cmd *) exec_cmd->redirs, shell) == EXIT_SUCCESS)
		{
			exit_status = ft_write_env(shell);
			free_cmd_tree(shell->parsed_tree);
			free_env(shell);
			exit(exit_status);
		}
		free_cmd_tree(shell->parsed_tree);
		free_env(shell);
		exit(EXIT_FAILURE);
	}
	return (exec_waitpid(pid));
}

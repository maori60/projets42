/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:46:55 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 18:22:56 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>

static int	handle_builtin(t_exec_cmd *exec_cmd, t_shell *shell)
{
	if (get_builtin_type(exec_cmd) != NOT_BUILTIN)
	{
		g_status = builtin(exec_cmd, get_builtin_type(exec_cmd), shell);
		return (g_status);
	}
	return (-1);
}

static void	exit_fork(t_shell *shell, int code)
{
	free_cmd_tree(shell->parsed_tree);
	free_env(shell);
	exit(code);
}

static void	execute(t_exec_cmd *cmd, t_shell *shell)
{
	signal_handle(EXEC_CHILD);
	if (run_cmd((t_cmd *) cmd->redirs, shell) == EXIT_SUCCESS)
	{
		if (cmd->path != NULL)
		{
			if (execve(cmd->path, cmd->args, cmd->env) == -1)
			{
				ft_fprintf(2, "minishell:%s %s\n", cmd->path, strerror(errno));
				exit_fork(shell, EXIT_FAILURE);
			}
		}
		exit_fork(shell, EXIT_SUCCESS);
	}
	exit_fork(shell, EXIT_FAILURE);
}

int	run_exec(t_cmd *cmd, t_shell *shell)
{
	t_exec_cmd	*exec_cmd;
	pid_t		pid;

	exec_cmd = (t_exec_cmd *) cmd;
	if (exec_cmd && exec_cmd->redirs)
	{
		g_status = expand_redir((t_cmd *) exec_cmd->redirs, shell->envs);
		if (g_status != EXIT_SUCCESS)
			return (g_status);
	}
	g_status = expand_exec(cmd, shell->envs);
	if (g_status != EXIT_SUCCESS)
		return (g_status);
	signal_handle(WAITING_PARENT);
	if (handle_builtin(exec_cmd, shell) != -1)
		return (g_status);
	pid = fork_call();
	if (pid == 0)
		execute(exec_cmd, shell);
	return (exec_waitpid(pid));
}

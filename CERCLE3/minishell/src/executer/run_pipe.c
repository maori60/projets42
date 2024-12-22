/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:48:29 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 18:23:10 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pipe_left(t_pipe_cmd *pipe_cmd, pid_t pid1, int p[2],
	t_shell *shell)
{
	int	exit_status;

	exit_status = 0;
	if (pid1 == 0)
	{
		if (close(p[0]) != 0)
			error_exit("close failed in run_pipe() A");
		if (dup2(p[1], STDOUT_FILENO) == -1)
			error_exit("dup2 failed in run_pipe()");
		if (close(p[1]) != 0)
			error_exit("close failed in run_pipe() B");
		exit_status = run_cmd(pipe_cmd->left, shell);
		free_cmd_tree(shell->parsed_tree);
		free_env(shell);
		exit(exit_status);
	}
	return (0);
}

static int	pipe_right(t_pipe_cmd *pipe_cmd, pid_t pid2, int p[2],
			t_shell *shell)
{
	int	exit_status;

	exit_status = 0;
	if (pid2 == 0)
	{
		if (close(p[1]) != 0)
			error_exit("close failed in run_pipe() C");
		if (dup2(p[0], STDIN_FILENO) == -1)
			error_exit("dup2 failed in run_pipe()");
		if (close(p[0]) != 0)
			error_exit("close failed in run_pipe() D");
		exit_status = run_cmd(pipe_cmd->right, shell);
		free_cmd_tree(shell->parsed_tree);
		free_env(shell);
		exit(exit_status);
	}
	return (0);
}

static void	close_parent_pipe(int p[2])
{
	if (close(p[0]) != 0)
		error_exit("close failed in run_pipe() E");
	if (close(p[1]) != 0)
		error_exit("close failed in run_pipe() F");
}

int	run_pipe(t_cmd *cmd, t_shell *shell)
{
	t_pipe_cmd	*pipe_cmd;
	int			p[2];
	pid_t		pid1;
	pid_t		pid2;
	int			exit_status;

	pipe_cmd = (t_pipe_cmd *) cmd;
	if (pipe(p) != 0)
		error_exit("pipe failed in run_pipe()");
	signal_handle(WAITING_PARENT);
	pid1 = fork_call();
	pipe_left(pipe_cmd, pid1, p, shell);
	pid2 = fork_call();
	pipe_right(pipe_cmd, pid2, p, shell);
	close_parent_pipe(p);
	exit_status = exec_waitpid(pid1);
	exit_status = exec_waitpid(pid2);
	return (exit_status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:48:00 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 12:09:23 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_redir_err(char *message, t_shell *shell)
{
	perror(message);
	free_cmd_tree(shell->parsed_tree);
	free_env(shell);
	exit(EXIT_FAILURE);
}

static int	run_heredoc(t_redir_cmd *redir_cmd, t_shell *shell)
{
	if (dup2(redir_cmd->fd, STDIN_FILENO) == -1)
		exit_redir_err("dup2_failed in run_heredoc", shell);
	if (close(redir_cmd->fd) != 0)
		exit_redir_err("close failed in run_heredoc", shell);
	return (EXIT_SUCCESS);
}

int	run_redir(t_cmd *cmd, t_shell *shell)
{
	t_redir_cmd	*redir_cmd;
	int			new_fd;

	redir_cmd = (t_redir_cmd *) cmd;
	if (redir_cmd->mode == -1)
		run_heredoc(redir_cmd, shell);
	else
	{
		new_fd = open(redir_cmd->filename, redir_cmd->mode, 0664);
		if (new_fd == -1)
			exit_redir_err("minishell: open failed in run_redir", shell);
		if (dup2(new_fd, redir_cmd->fd) == -1)
			exit_redir_err("minishell: dup2 failed in run_redir", shell);
		if (close(new_fd) != 0)
			exit_redir_err("minishell: close failed in run_redir", shell);
	}
	return (run_cmd(redir_cmd->cmd, shell));
}

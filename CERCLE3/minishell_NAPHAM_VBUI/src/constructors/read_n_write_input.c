/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_write_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:37 by napham            #+#    #+#             */
/*   Updated: 2024/12/20 20:32:43 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*hd_perror(t_redir_cmd *cmd, char *str, int fd, char *m)
{
	perror(m);
	if (cmd != NULL)
		free(cmd);
	if (str != NULL)
		free(str);
	if (fd > -1)
		close(fd);
	return (NULL);
}

t_cmd	*hd_stderror(t_redir_cmd *cmd, char *str, int fd, char *m)
{
	write_to_stderr(m);
	if (cmd != NULL)
	{
		if (cmd->fd > 2)
			close(cmd->fd);
		free(cmd);
	}
	if (str != NULL)
		free(str);
	if (fd > -1)
		close(fd);
	return (NULL);
}

static t_cmd	*write_in_file(t_redir_cmd *cmd, char *line, int fd)
{
	if (line == NULL)
		return (NULL);
	if (write(fd, line, ft_strlen(line)) == -1)
		return (hd_stderror(cmd, cmd->filename, fd, "Heredoc write A Failed"));
	if (write(fd, "\n", 1) == -1)
		return (hd_stderror(cmd, cmd->filename, fd, "Heredoc write B Failed"));
	return ((t_cmd *) cmd);
}

static	t_cmd	*write_failure(t_redir_cmd *cmd, int fd1, int fd2, char *line)
{
	signal_handle(SHELL_PARENT);
	free(line);
	if (read(STDIN_FILENO, NULL, 0) == -1)
	{
		if (dup2(fd1, STDIN_FILENO) == -1)
		{
			close(fd1);
			return (hd_stderror(cmd, cmd->filename, fd2, "Heredoc Dup2 Fail"));
		}
		close(fd1);
		return (hd_stderror(cmd, cmd->filename, fd2, "Heredoc Interrupted"));
	}
	close(fd1);
	return ((t_cmd *) cmd);
}

t_cmd	*read_n_write_input(t_redir_cmd *cmd, char *delim, int fd)
{
	int		saved_stdin;
	char	*line;

	saved_stdin = dup(STDIN_FILENO);
	signal_handle(HEREDOC);
	line = readline("heredoc> ");
	while (ft_strcmp(line, delim))
	{
		if (write_in_file(cmd, line, fd) == NULL)
			return (write_failure(cmd, saved_stdin, fd, line));
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
	signal_handle(SHELL_PARENT);
	close(saved_stdin);
	return ((t_cmd *) cmd);
}

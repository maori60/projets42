/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redircmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:24:58 by vbui              #+#    #+#             */
/*   Updated: 2024/12/20 20:32:51 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/readline.h>

t_cmd	*heredoc_cmd(t_redir_cmd *cmd, char *delimiter)
{
	int		temp_fd;

	temp_fd = open(HEREDOC_FILENAME, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (temp_fd < 0)
		return (hd_perror(cmd, NULL, -1, HEREDOC_FILENAME));
	cmd->fd = open(HEREDOC_FILENAME, O_RDONLY);
	if (cmd->fd < 0)
		return (hd_perror(cmd, cmd->filename, temp_fd, HEREDOC_FILENAME));
	if (unlink(HEREDOC_FILENAME) != 0)
		return (hd_perror(cmd, cmd->filename, temp_fd, HEREDOC_FILENAME));
	cmd->filename = ft_strdup(HEREDOC_FILENAME);
	if (cmd->filename == NULL)
		return (hd_stderror(cmd, NULL, temp_fd, "Malloc failed for heredoc\n"));
	cmd->mode = -1;
	if (read_n_write_input(cmd, delimiter, temp_fd) == NULL)
		return (NULL);
	if (close(temp_fd) != 0)
		return (hd_perror(cmd, cmd->filename, -1, HEREDOC_FILENAME));
	free(delimiter);
	return ((t_cmd *) cmd);
}

t_cmd	*redircmd(t_cmd *command, int fd, char *filename, int mode)
{
	t_redir_cmd	*cmd;

	cmd = malloc(sizeof(t_redir_cmd));
	if (cmd == NULL)
	{
		perror("Malloc for redir command failed");
		return (NULL);
	}
	cmd->type = REDIR;
	cmd->cmd = command;
	if (mode == -1)
		return (heredoc_cmd(cmd, filename));
	cmd->fd = fd;
	cmd->filename = filename;
	cmd->mode = mode;
	return ((t_cmd *) cmd);
}

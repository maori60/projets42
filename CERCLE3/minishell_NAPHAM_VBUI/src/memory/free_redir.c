/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:16:50 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 19:43:33 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*free_redir(t_cmd *cmd)
{
	t_redir_cmd	*redir_cmd;
	t_cmd		*next;

	redir_cmd = (t_redir_cmd *) cmd;
	next = redir_cmd->cmd;
	if (redir_cmd->mode == -1)
		close(redir_cmd->fd);
	free(redir_cmd->filename);
	free_cmd_tree(next);
	free(redir_cmd);
	return (NULL);
}

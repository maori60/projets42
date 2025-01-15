/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:15:39 by vbui              #+#    #+#             */
/*   Updated: 2024/12/21 00:17:54 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*free_cmd_tree(t_cmd *cmd)
{
	if (cmd == NULL)
		return (NULL);
	if (cmd->type == EXEC)
		free_exec(cmd);
	else if (cmd->type == REDIR)
		free_redir(cmd);
	else if (cmd->type == PIPE)
		free_pipe(cmd);
	return (NULL);
}

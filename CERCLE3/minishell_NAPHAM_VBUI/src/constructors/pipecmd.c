/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipecmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:25:27 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 10:26:59 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*pipecmd(t_cmd *left, t_cmd *right)
{
	t_pipe_cmd	*cmd;

	cmd = malloc(sizeof(t_pipe_cmd));
	if (cmd == NULL)
	{
		perror("Malloc for pipe command failed");
		return (NULL);
	}
	cmd->left = left;
	cmd->right = right;
	cmd->type = PIPE;
	return ((t_cmd *) cmd);
}

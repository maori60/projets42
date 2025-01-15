/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:24:16 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 10:27:06 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*execcmd(char **args, char **env, char *path)
{
	t_exec_cmd	*cmd;

	cmd = malloc(sizeof(t_exec_cmd));
	if (cmd == NULL)
	{
		perror("Malloc failed for exec command");
		return (NULL);
	}
	cmd->args = args;
	cmd->env = env;
	cmd->path = path;
	cmd->type = EXEC;
	return ((t_cmd *) cmd);
}

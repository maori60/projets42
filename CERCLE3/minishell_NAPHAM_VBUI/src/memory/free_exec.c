/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:16:18 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 11:40:05 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*free_exec(t_cmd *cmd)
{
	t_exec_cmd	*exec_cmd;

	exec_cmd = (t_exec_cmd *) cmd;
	free(exec_cmd->path);
	free_strvect(exec_cmd->args);
	free_array(exec_cmd->env);
	free_cmd_tree((t_cmd *) exec_cmd->redirs);
	free(exec_cmd);
	return (NULL);
}

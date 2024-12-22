/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:17:16 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 10:17:32 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*free_pipe(t_cmd *cmd)
{
	t_pipe_cmd	*pipe_cmd;
	t_cmd		*next_left;
	t_cmd		*next_right;

	pipe_cmd = (t_pipe_cmd *) cmd;
	next_left = pipe_cmd->left;
	next_right = pipe_cmd->right;
	free_cmd_tree(next_left);
	free_cmd_tree(next_right);
	free(pipe_cmd);
	return (NULL);
}

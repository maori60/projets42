/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:46:01 by vbui              #+#    #+#             */
/*   Updated: 2024/12/21 00:10:14 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_cmd(t_cmd *cmd, t_shell *shell)
{
	if (cmd == NULL)
		return (EXIT_SUCCESS);
	if (cmd->type == EXEC)
		return (run_exec(cmd, shell));
	else if (cmd->type == REDIR)
		return (run_redir(cmd, shell));
	else if (cmd->type == PIPE)
		return (run_pipe(cmd, shell));
	else
		return (EXIT_FAILURE);
}

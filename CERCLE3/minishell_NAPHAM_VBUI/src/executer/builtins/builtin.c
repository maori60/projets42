/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:01:50 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 15:18:00 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
/**
 * @brief      Determines whether the specified line is builtin.
 *
 * @param      line  The line
 *
 * @return     index of builtin if the specified line is builtin, i_not_builtin
 *             otherwise.
 */
t_builtin	get_builtin_type(t_exec_cmd *cmd)
{
	if (cmd->args[0] == NULL)
		return (NOT_BUILTIN);
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		return (CD);
	if (ft_strcmp(cmd->args[0], "echo") == 0)
		return (ECHO);
	if (ft_strcmp(cmd->args[0], "env") == 0)
		return (ENV);
	if (ft_strcmp(cmd->args[0], "exit") == 0)
		return (EXIT);
	if (ft_strcmp(cmd->args[0], "export") == 0)
		return (EXPORT);
	if (ft_strcmp(cmd->args[0], "pwd") == 0)
		return (PWD);
	if (ft_strcmp(cmd->args[0], "unset") == 0)
		return (UNSET);
	return (NOT_BUILTIN);
}

int	builtin(t_exec_cmd *cmd, t_builtin i, t_shell *shell)
{
	int			len;

	len = 0;
	while (cmd->args[len])
		len++;
	if (i == ECHO)
		return (ft_echo(cmd, shell));
	if (i == CD)
		return (ft_cd(cmd->args, len, shell));
	if (i == PWD)
		return (ft_pwd(cmd, shell));
	if (i == EXPORT)
		return (ft_export(cmd, len, shell));
	if (i == UNSET)
		return (ft_unset(cmd->args, len, shell));
	if (i == ENV)
		return (ft_env(cmd, shell));
	if (i == EXIT)
		return (ft_exit(cmd->args, len, shell));
	else
		return (0);
}

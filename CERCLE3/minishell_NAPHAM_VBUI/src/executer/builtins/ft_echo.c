/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:18:26 by napham            #+#    #+#             */
/*   Updated: 2024/12/20 20:35:53 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

static int	write_loop(char *str, char *next_str)
{
	if (secure_write_fd(1, str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (next_str != NULL)
	{
		if (secure_write_fd(1, " ") == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_write(char **cmd)
{
	int		print_newline;
	int		i;

	i = 1;
	print_newline = 1;
	while (cmd[i] && ft_strcmp(cmd[i], "-n") == 0)
	{
		print_newline = 0;
		i++;
	}
	while (cmd[i])
	{
		if (write_loop(cmd[i], cmd[i + 1]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (print_newline == 1)
	{
		if (secure_write_fd(1, "\n") == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_echo(t_exec_cmd *exec_cmd, t_shell *shell)
{
	pid_t	pid;
	int		exit_status;

	pid = fork_call();
	if (pid == 0)
	{
		if (run_cmd((t_cmd *) exec_cmd->redirs, shell) == EXIT_SUCCESS)
		{
			exit_status = ft_write(exec_cmd->args);
			free_cmd_tree(shell->parsed_tree);
			free_env(shell);
			exit(exit_status);
		}
		free_cmd_tree(shell->parsed_tree);
		free_env(shell);
		exit(EXIT_FAILURE);
	}
	return (exec_waitpid(pid));
}

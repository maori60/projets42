/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:25:52 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 14:21:14 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <linux/limits.h>

int	ft_write_pwd(t_shell *shell)
{
	char	buf[PATH_MAX];

	if (getcwd(buf, sizeof(buf)))
	{
		if (secure_write_fd(1, buf) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (secure_write_fd(1, "\n") == EXIT_FAILURE)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	else if (get_env_value("PWD", shell->envs))
	{
		if (secure_write_fd(1,
				get_env_value("PWD", shell->envs)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (secure_write_fd(1, "\n") == EXIT_FAILURE)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_fprintf(2, GETCWD_ERROR, "No such file or directory\n");
		return (EXIT_FAILURE);
	}
}

int	ft_pwd(t_exec_cmd *exec_cmd, t_shell *shell)
{
	pid_t	pid;
	int		exit_status;

	pid = fork_call();
	if (pid == 0)
	{
		if (run_cmd((t_cmd *) exec_cmd->redirs, shell) == EXIT_SUCCESS)
		{
			exit_status = ft_write_pwd(shell);
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

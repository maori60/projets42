/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:53:51 by napham            #+#    #+#             */
/*   Updated: 2024/12/20 20:39:14 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	secure_print_env(t_env *list)
{
	if (secure_write_fd(1, "declare -x ") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (secure_write_fd(1, list->name) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (secure_write_fd(1, "=\"") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (secure_write_fd(1, list->value) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (secure_write_fd(1, "\"\n") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	print_export_env(t_shell *shell)
{
	t_env	*tmp;
	t_env	*tmp_head;

	tmp = copy_list(shell->envs->head);
	tmp_head = tmp;
	if (tmp)
		bubble_sort_list(tmp);
	while (tmp)
	{
		if (secure_print_env(tmp) == EXIT_FAILURE)
		{
			free_list (tmp_head);
			return (EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	free_list(tmp_head);
	return (EXIT_SUCCESS);
}

static bool	is_valid_argument(char *arg)
{
	int	i;

	if (arg[0] == '\0' || arg[0] == '=' || ft_isdigit(arg[0]))
		return (false);
	i = 0;
	while (arg[i] != '\0' && arg[i] != '=' && is_var_char(arg[i]))
		i++;
	if (arg[i] == '\0' || arg[i] == '=')
		return (true);
	else
		return (false);
}

static int	ft_export_add_env(char **cmd, t_shell *shell)
{
	char	*name;
	char	*value;
	int		i;
	int		j;

	i = 0;
	while (cmd[++i])
	{
		j = 0;
		while (cmd[i][j] && cmd[i][j] != '=')
			j++;
		name = ft_substr(cmd[i], 0, j);
		value = ft_substr(cmd[i], j + 1, ft_strlen(cmd[i]));
		if (!is_valid_argument(cmd[i]))
		{
			ft_fprintf(2, ERR_EXPORT, cmd[i]);
			g_status = EXIT_FAILURE;
		}
		else
			add_env(name, value, shell);
		free(name);
		free(value);
	}
	return (g_status);
}

int	ft_export(t_exec_cmd *exec_cmd, int len, t_shell *shell)
{
	pid_t	pid;
	int		exit_status;

	if (!shell->envs->head || !shell->envs || !shell->envs->size)
		set_default_env(shell);
	if (len == 1)
	{
		pid = fork_call();
		if (pid == 0)
		{
			if (run_cmd((t_cmd *) exec_cmd->redirs, shell) == EXIT_SUCCESS)
			{
				exit_status = print_export_env(shell);
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
	else
		return (ft_export_add_env(exec_cmd->args, shell));
}

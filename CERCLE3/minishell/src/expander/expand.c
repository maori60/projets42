/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:17:10 by vbui              #+#    #+#             */
/*   Updated: 2024/12/21 00:56:29 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <unistd.h>

int	expand_tree(t_cmd *cmd, t_envs *env_list)
{
	if (cmd == NULL)
		return (EXIT_SUCCESS);
	if (cmd->type == EXEC)
		return (expand_exec(cmd, env_list));
	else if (cmd->type == REDIR)
		return (expand_redir(cmd, env_list));
	else if (cmd->type == PIPE)
		return (expand_pipe(cmd, env_list));
	else
		return (EXIT_FAILURE);
}

int	expand_exec(t_cmd *cmd, t_envs *env_list)
{
	t_exec_cmd	*exec_cmd;

	exec_cmd = (t_exec_cmd *) cmd;
	exec_cmd->args = expand_array(exec_cmd->args, env_list);
	if (exec_cmd->args == NULL || exec_cmd->args[0] == NULL)
		return (g_status);
	exec_cmd->env = env_list_to_env_array(env_list);
	if (get_builtin_type(exec_cmd) == NOT_BUILTIN)
	{
		exec_cmd->path = get_path(exec_cmd->args[0], env_list);
		g_status = check_path(exec_cmd->path, exec_cmd->args[0]);
		if (g_status != EXIT_SUCCESS)
			return (g_status);
	}
	else
		exec_cmd->path = ft_strdup("builtin");
	return (expand_tree((t_cmd *) exec_cmd->redirs, env_list));
}

int	expand_redir(t_cmd *cmd, t_envs *env_list)
{
	t_redir_cmd	*redir_cmd;
	char		**array;

	redir_cmd = (t_redir_cmd *) cmd;
	array = ft_calloc(sizeof(char *), 2);
	array[0] = ft_strdup(redir_cmd->filename);
	array = expand_array(array, env_list);
	if (len_array(array) != 1)
	{
		free_array(array);
		ft_putstr_fd("minishell: ambiguous redirect\n", 2);
		return (1);
	}
	free(redir_cmd->filename);
	redir_cmd->filename = array[0];
	free(array);
	if (redir_cmd->mode == O_RDONLY
		&& access(redir_cmd->filename, F_OK) == -1)
	{
		ft_fprintf(2, ERR_NO_FILE, redir_cmd->filename);
		return (1);
	}
	return (expand_tree(redir_cmd->cmd, env_list));
}

int	expand_pipe(t_cmd *cmd, t_envs *env_list)
{
	t_pipe_cmd	*pipe_cmd;
	int			error_left;
	int			error_right;

	pipe_cmd = (t_pipe_cmd *) cmd;
	error_left = expand_tree(pipe_cmd->left, env_list);
	error_right = expand_tree(pipe_cmd->right, env_list);
	if (error_left == 0 && error_right == 0)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

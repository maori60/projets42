/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:07:05 by napham            #+#    #+#             */
/*   Updated: 2024/12/21 01:41:03 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>

static int	is_directory(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

int	check_path(char *path, char *arg)
{
	if (path == NULL || access(path, F_OK) == -1)
	{
		if (ft_strchr(path, '/'))
			ft_fprintf(2, ERR_NO_FILE, arg);
		else
			ft_fprintf(2, CMD_NOT_FOUND, arg);
		return (127);
	}
	if (access(path, X_OK) == -1 || is_directory(arg))
	{
		if (is_directory(path))
			ft_fprintf(2, "minishell: %s: %s\n", arg, "Is a directory");
		else
			ft_fprintf(2, "minishell: %s: %s\n", arg, "Permission denied");
		return (126);
	}
	return (EXIT_SUCCESS);
}

static char	*find_path(char **path_split, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (path_split && path_split[i])
	{
		tmp = ft_strjoin(path_split[i], cmd);
		if (tmp == NULL)
		{
			ft_fprintf(2, "minishell: malloc failed\n");
			return (NULL);
		}
		if (access(tmp, F_OK) == 0 && !is_directory(tmp))
		{
			free_array(path_split);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	free_array(path_split);
	return (NULL);
}

int	path_split_append_slash(char **path_split)
{
	char	*tmp;
	int		i;

	i = 0;
	while (path_split && path_split[i])
	{
		if (path_split[i][ft_strlen(path_split[i]) - 1] != '/')
		{
			tmp = path_split[i];
			path_split[i] = ft_strjoin(path_split[i], "/");
			if (path_split[i] == NULL)
			{
				path_split[i] = tmp;
				ft_fprintf(2, "minishell: malloc failed\n");
				return (1);
			}
			free(tmp);
		}
		i++;
	}
	return (0);
}

char	*get_path(char *cmd, t_envs *envs)
{
	char		**path_split;
	const char	*paths = get_env_value("PATH", envs);

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/') != NULL || paths == NULL)
		return (ft_strdup(cmd));
	path_split = ft_split(paths, ':');
	if (!path_split)
	{
		ft_fprintf(2, "minishell: malloc failed\n");
		return (NULL);
	}
	if (path_split_append_slash(path_split) == 1)
	{
		ft_fprintf(2, "minishell: malloc failed\n");
		return (NULL);
	}
	return (find_path(path_split, cmd));
}

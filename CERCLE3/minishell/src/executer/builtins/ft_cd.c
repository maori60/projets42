/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:41:30 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 13:53:38 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "libft.h"

static char	*get_cdpath(char *cmd, const char *cdpath)
{
	char		*command[2];
	char		**paths[2];

	if (!cmd || !cdpath)
		return (NULL);
	paths[0] = ft_split(cdpath, ':');
	paths[1] = paths[0];
	if (path_split_append_slash(paths[0]) == 1)
		return (NULL);
	while (paths[0] && *paths[0])
	{
		command[1] = ft_strjoin(*paths[0], cmd);
		if (access(command[1], F_OK) == 0)
		{
			printf("%s\n", command[1]);
			free_array(paths[1]);
			return (command[1]);
		}
		free(command[1]);
		paths[0]++;
	}
	free_array(paths[1]);
	return (ft_strdup(cmd));
}

static char	*get_dir(char **cmd, int len, t_shell *shell)
{
	char		*dir;

	dir = NULL;
	if (len == 1 || (len == 2 && ft_strcmp(cmd[1], "--") == 0))
	{
		dir = get_env_value("HOME", shell->envs);
		if (!dir)
			ft_fprintf(2, "minishell: cd:HOME not set\n");
	}
	else if (len == 2 && ft_strcmp(cmd[1], "-") == 0)
	{
		dir = get_env_value("OLDPWD", shell->envs);
		if (!dir)
			ft_fprintf(2, "minishell: cd: OLDPWD not set\n");
	}	
	else if (ft_strncmp(cmd[1], "/", 1) && get_env_value("CDPATH", shell->envs))
		dir = get_cdpath(cmd[1], get_env_value("CDPATH", shell->envs));
	else
		dir = cmd[1];
	return (dir);
}

static int	update_pwd_env( t_shell *shell)
{
	char	*buf;

	buf = get_env_value("PWD", shell->envs);
	if (buf)
	{
		if (add_env("OLDPWD", buf, shell) == -1)
		{
			ft_fprintf(2, "minishell: cd: malloc error: OLDPWD not set\n");
			return (EXIT_FAILURE);
		}
	}
	else
		unset_var("OLDPWD", shell);
	buf = getcwd(NULL, 0);
	if (buf == NULL)
	{
		ft_fprintf(2, GETCWD_ERROR, strerror(errno));
		return (EXIT_FAILURE);
	}
	if (add_env("PWD", buf, shell) == -1)
		return (EXIT_FAILURE);
	free(buf);
	return (0);
}

static void	free_cdpath(char *dir, char **cmd, int len, t_shell *shell)
{
	if (len == 2 && get_env_value("CDPATH", shell->envs)
		&& ft_strcmp(cmd[1], "--")
		&& ft_strcmp(cmd[1], "-") && ft_strncmp(cmd[1], "/", 1))
		free(dir);
}

int	ft_cd(char **cmd, int len, t_shell *shell)
{
	char		*dir;

	if (len > 2)
	{
		ft_fprintf(2, "minishell: cd: too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	dir = get_dir(cmd, len, shell);
	if (dir == NULL)
		return (EXIT_FAILURE);
	if (chdir(dir) == -1)
	{
		ft_fprintf(2, "minishell: cd: %s: %s\n", dir, strerror(errno));
		free_cdpath(dir, cmd, len, shell);
		return (EXIT_FAILURE);
	}
	if (len == 2 && ft_strcmp(cmd[1], "-") == 0)
		ft_putendl_fd(dir, STDOUT_FILENO);
	if (update_pwd_env(shell) == EXIT_FAILURE)
		g_status = 1;
	free_cdpath(dir, cmd, len, shell);
	return (g_status);
}

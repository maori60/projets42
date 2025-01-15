/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:50:18 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 17:31:32 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_default_env(t_shell *shell)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (add_env("PWD", pwd, shell) || add_env("SHLVL", "1", shell)
		|| add_env("OLDPWD", "", shell))
		return (1);
	return (0);
}

int	init_env_shell(char **env, t_shell *shell)
{
	char	*name;
	char	*value;
	int		i;
	int		j;

	shell->envs = malloc(sizeof(t_envs));
	if (!shell->envs)
		ft_print_error(MEMO_ERROR, 1);
	shell->envs->size = 0;
	i = -1;
	if (!env || !env[0])
		return (set_default_env(shell));
	while (env[++i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		name = ft_substr(env[i], 0, j);
		value = ft_substr(env[i], j + 1, ft_strlen(env[i]));
		if (add_env(name, value, shell) == 1)
			safe_exit(NULL, shell);
		free(name);
		free(value);
	}
	return (0);
}

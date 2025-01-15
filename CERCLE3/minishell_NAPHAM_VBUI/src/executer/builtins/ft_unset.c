/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:33:04 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 21:02:07 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

int	unset_var(char *cmd, t_shell *shell)
{
	t_env	*tmp;

	tmp = find_env(cmd, shell->envs);
	if (tmp)
	{
		del_node(tmp, shell);
		shell->envs->size--;
	}
	return (0);
}

int	ft_unset(char **cmd, int len, t_shell *shell)
{
	int		i;

	if (len == 1)
		return (0);
	i = 0;
	while (cmd[++i])
		unset_var(cmd[i], shell);
	return (0);
}

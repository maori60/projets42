/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:52:03 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 21:02:58 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char *name, t_envs *envs)
{
	t_env	*tmp;

	tmp = find_env(name, envs);
	if (tmp)
		return (tmp->value);
	return (NULL);
}

t_env	*find_env(char *name, t_envs *env_list)
{
	t_env	*tmp;

	if (!name || !name[0] || !env_list || env_list->size == 0)
		return (NULL);
	tmp = env_list->head;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

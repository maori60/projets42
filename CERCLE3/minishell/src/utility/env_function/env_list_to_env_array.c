/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_env_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:05:04 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 15:08:51 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_list_to_env_array(t_envs *env_list)
{
	char	**env_array;
	char	*tmp_char;
	t_env	*tmp;
	int		i;

	env_array = (char **)malloc(sizeof(char *) * (env_list->size + 1));
	if (!env_array)
		return (NULL);
	tmp = env_list->head;
	i = -1;
	while (++i < env_list->size)
	{
		tmp_char = ft_strjoin(tmp->name, "=");
		if (!tmp_char)
			return (free_array(env_array));
		env_array[i] = ft_strjoin(tmp_char, tmp->value);
		if (!env_array[i])
			return (free_array(env_array));
		free(tmp_char);
		tmp = tmp->next;
	}
	env_array[i] = NULL;
	return (env_array);
}

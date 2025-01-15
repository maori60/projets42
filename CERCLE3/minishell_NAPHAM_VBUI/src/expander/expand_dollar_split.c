/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:01:54 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 13:42:58 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

int	expand_env_var_split(t_envs *env_list, char *str, char **new_str,
	t_arg_list *expanded_list)
{
	t_env	*env_tmp;
	char	**array;
	char	*tmp;
	int		i[2];

	i[0] = 1;
	tmp = *new_str;
	env_tmp = find_env_and_copy_value(str, env_list, &i[0]);
	if (env_tmp)
	{
		array = ft_split_charset(env_tmp->value, WHITESPACES);
		i[1] = 0;
		while (array && array[i[1]])
		{
			*new_str = ft_strjoin(tmp, array[i[1]]);
			free(tmp);
			if (array[++i[1]])
			{
				tmp = ft_strdup("");
				insert_back(expanded_list, *new_str);
			}
		}
		free_array(array);
	}
	return (i[0]);
}

int	expand_dollar_split(char *str, char **new_str, t_envs *env_list,
		t_arg_list *expanded_list)
{
	int		i;
	char	*tmp;
	char	*val;

	i = 1;
	tmp = *new_str;
	if (str[1] == *QUESTION_MARK)
	{
		val = ft_itoa(g_status);
		*new_str = ft_strjoin(tmp, val);
		free(val);
		free(tmp);
		i++;
	}
	else if (str[1] == *DOUBLE_QUOTE || str[1] == *SINGLE_QUOTE)
		i = add_char("", new_str);
	else if (ft_strchr(WHITESPACES, str[1]) || !is_var_char(str[1]))
		i = add_char(DOLLAR_SIGN, new_str);
	else
		i += expand_env_var_split(env_list, str, new_str, expanded_list);
	return (i);
}

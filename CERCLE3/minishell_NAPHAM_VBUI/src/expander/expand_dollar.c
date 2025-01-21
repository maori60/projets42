/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:01:54 by napham            #+#    #+#             */
/*   Updated: 2024/12/21 00:24:18 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_env	*find_env_and_copy_value(char *str, t_envs *env_list, int *i)
{
	t_env	*env_tmp;
	char	*tmp;

	while (is_var_char(str[*i]) || ft_isdigit(str[*i]))
		(*i)++;
	tmp = ft_substr(str, 1, --(*i));
	env_tmp = find_env(tmp, env_list);
	free(tmp);
	return (env_tmp);
}

int	expand_env_var(t_envs *env_list, char *str, char **new_str)
{
	t_env	*env_tmp;
	char	*tmp;
	int		i;

	i = 1;
	tmp = *new_str;
	env_tmp = find_env_and_copy_value(str, env_list, &i);
	if (env_tmp)
	{
		*new_str = ft_strjoin(tmp, env_tmp->value);
		free(tmp);
	}
	return (i);
}

int	expand_dollar(char *str, char **new_str, t_envs *env_list)
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
	else if (ft_strchr(WHITESPACES, str[1]) || !is_var_char(str[i]))
		i = add_char(DOLLAR_SIGN, new_str);
	else
		i += expand_env_var(env_list, str, new_str);
	return (i);
}

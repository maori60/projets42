/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:43:55 by napham            #+#    #+#             */
/*   Updated: 2024/12/21 00:57:25 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	add_char(char *str, char **new_str)
{
	char	*tmp;
	char	*between;

	tmp = *new_str;
	between = ft_substr(str, 0, 1);
	*new_str = ft_strjoin(tmp, between);
	free(tmp);
	free(between);
	return (1);
}

static int	single_quote(char *str, char **new_str)
{
	int		count;
	char	*tmp;
	char	*between;

	count = find_pair(str, *SINGLE_QUOTE);
	tmp = *new_str;
	if (count == -1)
		return (add_char(SINGLE_QUOTE, new_str));
	between = ft_substr(str, 1, count - 1);
	*new_str = ft_strjoin(tmp, between);
	free(tmp);
	free(between);
	return (count + 1);
}

static int	expand_double_quote(char *str, char **new_str, t_envs *env_list)
{
	int	i;
	int	count;

	i = 1;
	count = find_pair(str, *DOUBLE_QUOTE);
	if (count == -1)
		return (add_char(DOUBLE_QUOTE, new_str));
	while (i < count)
	{
		if (str[i] == *DOLLAR_SIGN && (is_var_char(str[i + 1])
				|| str[i + 1] == *QUESTION_MARK))
			i += expand_dollar(&str[i], new_str, env_list);
		else
			i += add_char(&str[i], new_str);
	}
	return (i + 1);
}

bool	only_invalide_dollar(char *str, t_envs *env_list)
{
	t_env	*env_tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == *DOLLAR_SIGN && (is_var_char(str[i + 1])))
		{
			i++;
			env_tmp = find_env_and_copy_value(str, env_list, &i);
			if (!env_tmp || !env_tmp->value || !env_tmp->name)
			{
				if (!str[i + 1])
					return (true);
				continue ;
			}
			else
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

void	expand_str(char *arg, t_arg_list *exp_list, t_envs *env_list)
{
	int		i;
	char	*new_str;

	i = 0;
	if (only_invalide_dollar(arg, env_list) == true)
		return ;
	new_str = ft_calloc(1, sizeof(char));
	while (arg[i])
	{
		if (arg[i] == *SINGLE_QUOTE)
			i += single_quote(&arg[i], &new_str);
		else if (arg[i] == *DOUBLE_QUOTE)
			i += expand_double_quote(&arg[i], &new_str, env_list);
		else if (arg[i] == *DOLLAR_SIGN)
			i += expand_dollar_split(&arg[i], &new_str, env_list, exp_list);
		else
			i += add_char(&arg[i], &new_str);
	}
	insert_back(exp_list, new_str);
}

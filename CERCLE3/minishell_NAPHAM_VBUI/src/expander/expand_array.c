/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:02:17 by napham            #+#    #+#             */
/*   Updated: 2024/12/21 00:48:40 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char	**expand_array(char **args, t_envs *env_list)
{
	t_arg_list		*expanded;
	int				len;
	char			**new_args;
	int				i;

	if (!args || !*args)
		return (args);
	len = len_array(args);
	expanded = ft_calloc(1, sizeof(t_arg_list));
	if (expanded == NULL)
		return (args);
	i = -1;
	while (++i < len)
		expand_str(args[i], expanded, env_list);
	new_args = list_to_array(expanded);
	t_free_list(expanded, true);
	free_array(args);
	return (new_args);
}

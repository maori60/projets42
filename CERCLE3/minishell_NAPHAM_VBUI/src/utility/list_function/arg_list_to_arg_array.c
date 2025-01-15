/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list_to_arg_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:03:54 by vbui              #+#    #+#             */
/*   Updated: 2024/12/20 20:46:46 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*a_l_t_a_a_err(char *message, char **to_free)
{
	if (message != NULL)
		perror(message);
	if (to_free != NULL)
		free_array(to_free);
	return (NULL);
}

static int	get_list_size(t_arg_list *list)
{
	t_arg_list	*iter;
	int			size;

	iter = list;
	size = 0;
	while (iter != NULL)
	{
		size++;
		iter = iter->next;
	}
	return (size);
}

char	**arg_list_to_arg_array(t_arg_list *list)
{
	t_arg_list	*iter;
	char		**arg_array;
	int			size;
	int			i;

	iter = list;
	size = get_list_size(list);
	i = 0;
	arg_array = malloc((size + 1) * sizeof(char *));
	if (arg_array == NULL)
		return (a_l_t_a_a_err("Malloc failed for arg_array", NULL));
	iter = list;
	while (i < size)
	{
		arg_array[i] = malloc(iter->arg_length * sizeof(char));
		if (arg_array[i] == NULL)
			return (a_l_t_a_a_err("Malloc failed arg_array[i]", arg_array));
		ft_strlcpy(arg_array[i], iter->arg, iter->arg_length);
		i++;
		iter = iter->next;
	}
	arg_array[i] = NULL;
	return (arg_array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:13:40 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 10:18:50 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*free_array(char **arg_array)
{
	int	i;

	i = 0;
	if (arg_array == NULL)
		return (NULL);
	while (arg_array[i] != NULL)
	{
		free(arg_array[i]);
		i++;
	}
	free(arg_array);
	return (NULL);
}

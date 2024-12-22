/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 08:31:23 by vbui              #+#    #+#             */
/*   Updated: 2024/12/20 20:47:10 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_string(char *start, char *end)
{
	int		size;
	int		i;
	char	*string;

	if (start == NULL || end == NULL)
		return (NULL);
	size = end - start + 2;
	i = 0;
	string = malloc(sizeof(char) * size);
	if (string == NULL)
		return (NULL);
	while (i < size - 1)
	{
		string[i] = start[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

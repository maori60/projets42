/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strvect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:14:43 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 10:14:55 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*free_strvect(char **vect)
{
	int	i;

	if (vect == NULL)
		return (NULL);
	i = 0;
	while (vect[i] != NULL)
	{
		free(vect[i]);
		i++;
	}
	free(vect);
	return (NULL);
}

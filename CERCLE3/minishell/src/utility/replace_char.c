/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:00:23 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 22:03:42 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_char(char *str, char find, char replace)
{
	char	*current_pos;

	current_pos = ft_strchr(str, find);
	while (current_pos)
	{
		*current_pos = replace;
		current_pos = ft_strchr(current_pos, find);
	}
}

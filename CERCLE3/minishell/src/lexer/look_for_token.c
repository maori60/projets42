/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 08:42:29 by vbui              #+#    #+#             */
/*   Updated: 2024/12/20 20:42:54 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	look_for_token(char **scan_string, char *end_string)
{
	char	*s;

	s = *scan_string;
	if (s == end_string)
		return (END_TOKEN);
	while (s < end_string && (ft_strchr(WHITESPACES, *s)))
		s++;
	return (match(s, end_string));
}

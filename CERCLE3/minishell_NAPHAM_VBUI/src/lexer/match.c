/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:42:49 by vbui              #+#    #+#             */
/*   Updated: 2024/12/21 00:17:34 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	match_greater_lesser(char *symbol, char *end_scan)
{
	if (*symbol == '>')
	{
		if ((symbol + 1) < end_scan && *(symbol + 1) == '>')
			return (DOUBLE_GREATER);
		else
			return (GREATER);
	}
	else if (*symbol == '<')
	{
		if ((symbol + 1) < end_scan && *(symbol + 1) == '<')
			return (DOUBLE_LESSER);
		else
			return (LESSER);
	}
	return (BAD_TOKEN);
}

t_token	match(char *symbol, char *end_scan)
{
	if (symbol == NULL || end_scan == NULL || symbol > end_scan)
		return (BAD_TOKEN);
	else if (symbol == end_scan || *symbol == '\0')
		return (END_TOKEN);
	else if (*symbol == '>' || *symbol == '<')
		return (match_greater_lesser(symbol, end_scan));
	else if (*symbol == '|')
		return (VBAR);
	else
		return (WORD_TOKEN);
}

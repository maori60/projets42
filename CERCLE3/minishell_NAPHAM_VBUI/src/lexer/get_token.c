/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:47:22 by vbui              #+#    #+#             */
/*   Updated: 2024/12/21 00:16:25 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	read_quote(char **s, char *end_scan)
{
	char	*iter;
	char	*prob_endofword;
	char	quote_type;

	iter = *s;
	prob_endofword = NULL;
	quote_type = *(*s);
	iter++;
	while (iter < end_scan && *iter != quote_type)
	{
		if (prob_endofword == NULL && (ft_strchr(WHITESPACES, *iter)
				|| match(iter, end_scan) != WORD_TOKEN))
			prob_endofword = iter;
		iter++;
	}
	if (iter == end_scan && prob_endofword != NULL)
		*s = prob_endofword - 1;
	else if (iter == end_scan && prob_endofword == NULL)
		*s = iter - 1;
	else
		*s = iter;
	return (WORD_TOKEN);
}

static t_token	read_symbols(char **symbol, char *end_scan)
{
	t_token	token;

	if (symbol == NULL)
		return (BAD_TOKEN);
	else if (*symbol == NULL || *symbol == end_scan)
		return (END_TOKEN);
	token = match(*symbol, end_scan);
	if (token == DOUBLE_GREATER
		|| token == DOUBLE_LESSER)
		*symbol = *symbol + 1;
	else if (token == WORD_TOKEN)
	{
		while (*symbol < end_scan && !ft_strchr(WHITESPACES, **symbol)
			&& (match(*symbol, end_scan) == WORD_TOKEN))
		{
			if (*(*symbol) == '\'' || *(*symbol) == '\"')
				read_quote(symbol, end_scan);
			(*symbol)++;
		}
		(*symbol)--;
	}
	return (token);
}

t_token	get_token(char **scan_s, char *end_scan, char **token_s, char **token_e)
{
	char		*s;
	t_token		token;

	s = *scan_s;
	while (s < end_scan && ft_strchr(WHITESPACES, *s))
		s++;
	if (token_s != NULL)
		*token_s = s;
	token = read_symbols(&s, end_scan);
	if (token_e != NULL)
		*token_e = s;
	*scan_s = s + 1;
	return (token);
}

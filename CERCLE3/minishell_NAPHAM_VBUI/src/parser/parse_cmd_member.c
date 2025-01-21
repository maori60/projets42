/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_member.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:00:16 by vbui              #+#    #+#             */
/*   Updated: 2024/12/21 00:06:31 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parse_cmd_member(char **scan_pos, char *end_scan)
{
	t_cmd	*cmd_tree;
	t_token	token;

	token = look_for_token(scan_pos, end_scan);
	cmd_tree = NULL;
	if (token == WORD_TOKEN || token == LESSER || token == GREATER
		|| token == DOUBLE_GREATER || token == DOUBLE_LESSER)
		cmd_tree = parse_exec(scan_pos, end_scan);
	else
	{
		g_status = 2;
		write_to_stderr("Syntax Error: expected a command");
	}
	return (cmd_tree);
}

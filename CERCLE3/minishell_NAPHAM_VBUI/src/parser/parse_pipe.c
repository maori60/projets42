/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:03:07 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 15:04:03 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parse_pipe(t_cmd *tree, char **scan_pos, char *end_scan)
{
	t_cmd		*pipe_cmd;
	t_token		token;
	t_cmd		*right_side;

	if (tree == NULL)
	{
		g_status = 2;
		write_to_stderr("Invalid pipe branch");
		return (NULL);
	}
	token = get_token(scan_pos, end_scan, 0, 0);
	if (token != VBAR)
	{
		g_status = 2;
		write_to_stderr("Syntax Error: expected '|'");
		return (NULL);
	}
	right_side = parse_cmd_member(scan_pos, end_scan);
	if (right_side == NULL)
	{
		free_cmd_tree(tree);
		return (NULL);
	}
	pipe_cmd = pipecmd(tree, right_side);
	return (pipe_cmd);
}

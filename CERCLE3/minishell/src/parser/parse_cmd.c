/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:01:24 by vbui              #+#    #+#             */
/*   Updated: 2024/12/21 00:06:11 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	GRAMMAR:

	REDIR		-> [ < or << or > or >> ] word

	EXEC		-> {REDIR}+ {words}+ {REDIR}+

	CMD_MEMBER	-> EXEC

	PIPE		-> CMD_MEMBER [ | ] PIPE

	CMD (entry)	-> PIPE
*/

static t_cmd	*cmd_loop(t_token t, t_cmd *cmd_tree, char **s_p, char *e_s)
{
	while (t != END_TOKEN)
	{
		if (cmd_tree == NULL)
			return (NULL);
		if (t == VBAR)
			cmd_tree = parse_pipe(cmd_tree, s_p, e_s);
		else
		{
			g_status = 2;
			write_to_stderr("Syntax Error: expected '|'");
			free_cmd_tree(cmd_tree);
			return (NULL);
		}
		t = look_for_token(s_p, e_s);
	}
	return (cmd_tree);
}

t_cmd	*parse_cmd(char *input_string, char **input_progress)
{
	char	*end_scan;
	char	*scan_pos;
	t_token	token;
	t_cmd	*cmd_tree;

	scan_pos = input_string;
	end_scan = scan_pos + ft_strlen(input_string);
	token = look_for_token(&scan_pos, end_scan);
	if (token != END_TOKEN)
		cmd_tree = parse_cmd_member(&scan_pos, end_scan);
	else
		return (NULL);
	token = look_for_token(&scan_pos, end_scan);
	if (token != END_TOKEN && cmd_tree != NULL)
		cmd_tree = cmd_loop(token, cmd_tree, &scan_pos, end_scan);
	if (cmd_tree == NULL)
		return (NULL);
	if (input_progress != NULL)
		*input_progress = scan_pos;
	return (cmd_tree);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:04:15 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 15:04:47 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*p_redir_err(char *message)
{
	g_status = 2;
	if (message != NULL)
		write_to_stderr("Syntax Error: Invalid filename");
	return (NULL);
}

t_cmd	*parse_redir(t_cmd *cmd, char **scan_string, char *end_scan)
{
	t_token	type;
	char	*file_start;
	char	*file_end;
	char	*file_name;

	type = look_for_token(scan_string, end_scan);
	if (type != GREATER && type != DOUBLE_GREATER && type != LESSER
		&& type != DOUBLE_LESSER)
		return (cmd);
	type = get_token(scan_string, end_scan, 0, 0);
	if (get_token(scan_string, end_scan, &file_start, &file_end) != WORD_TOKEN)
		return (p_redir_err("Syntax Error: Invalid filename"));
	file_name = get_string(file_start, file_end);
	if (type == GREATER)
		cmd = redircmd(cmd, 1, file_name, O_WRONLY | O_CREAT | O_TRUNC);
	else if (type == LESSER)
		cmd = redircmd(cmd, 0, file_name, O_RDONLY);
	else if (type == DOUBLE_GREATER)
		cmd = redircmd(cmd, 1, file_name, O_WRONLY | O_CREAT | O_APPEND);
	else if (type == DOUBLE_LESSER)
		cmd = redircmd(cmd, 1, file_name, -1);
	if (cmd == NULL)
		free(file_name);
	return (cmd);
}

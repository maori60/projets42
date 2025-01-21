/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:03:45 by vbui              #+#    #+#             */
/*   Updated: 2024/12/20 20:44:25 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*p_e_err(t_exec_cmd *exec, t_arg_list *arg, t_redir_cmd *redir)
{
	if (exec != NULL)
		free(exec);
	if (arg != NULL)
		free_arg_list(arg);
	if (redir != NULL)
		free_cmd_tree((t_cmd *) redir);
	return (NULL);
}

static t_arg_list	*build_args(char **scan_p, char *scan_e, t_arg_list **list)
{
	t_arg_list	*element;
	char		*token_start;
	char		*token_end;

	get_token(scan_p, scan_e, &token_start, &token_end);
	if (*list == NULL)
	{
		*list = add_to_list(NULL, token_start, token_end);
		if (*list == NULL)
			return (NULL);
		return (*list);
	}
	else
	{
		element = add_to_list(*list, token_start, token_end);
		if (element == NULL)
			return (NULL);
		return (element);
	}
}

static t_redir_cmd	*build_redir(char **scan_p, char *scan_e, t_redir_cmd **re)
{
	t_redir_cmd	*iter;

	if (*re == NULL)
	{
		*re = (t_redir_cmd *) parse_redir(NULL, scan_p, scan_e);
		if (*re == NULL)
			return (NULL);
	}
	else
	{
		iter = *re;
		while (iter->cmd != NULL)
			iter = (t_redir_cmd *) iter->cmd;
		iter->cmd = parse_redir(NULL, scan_p, scan_e);
		if (iter->cmd == NULL)
			return (NULL);
	}
	return ((t_redir_cmd *) re);
}

static t_cmd	*merge(t_exec_cmd *exec, t_arg_list *arg, t_redir_cmd *redir)
{
	exec->args = arg_list_to_arg_array(arg);
	if (exec->args == NULL)
		return (p_e_err(exec, arg, redir));
	exec->redirs = redir;
	free_arg_list(arg);
	return ((t_cmd *) exec);
}

t_cmd	*parse_exec(char **s_p, char *e_s)
{
	t_exec_cmd	*exec;
	t_redir_cmd	*redir_list;
	t_arg_list	*arg_list;
	t_token		token;

	redir_list = NULL;
	arg_list = NULL;
	exec = (t_exec_cmd *) execcmd(0, 0, 0);
	if (exec == NULL)
		return (NULL);
	token = look_for_token(s_p, e_s);
	while (token == WORD_TOKEN || token == GREATER || token == LESSER
		|| token == DOUBLE_GREATER || token == DOUBLE_LESSER)
	{
		if (token == WORD_TOKEN)
		{
			if (build_args(s_p, e_s, &arg_list) == NULL)
				return (p_e_err(exec, arg_list, redir_list));
		}
		else
			if (build_redir(s_p, e_s, &redir_list) == NULL)
				return (p_e_err(exec, arg_list, redir_list));
		token = look_for_token(s_p, e_s);
	}
	return (merge(exec, arg_list, redir_list));
}

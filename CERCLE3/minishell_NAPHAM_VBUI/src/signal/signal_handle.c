/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:41:24 by napham            #+#    #+#             */
/*   Updated: 2024/12/20 20:45:28 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_heredoc(t_signal_type type)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	if (type == HEREDOC)
	{
		ignore_sigquit();
		act.sa_handler = &signal_ctlc_heredoc;
		sigaction(SIGINT, &act, NULL);
	}
	else if (type == WAITING_PARENT)
	{
		ignore_sigquit();
		act.sa_handler = SIG_IGN;
		sigaction(SIGINT, &act, NULL);
	}
}

void	signal_handle(t_signal_type type)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	if (type == SHELL_PARENT)
	{
		ignore_sigquit();
		act.sa_handler = &signal_reset_prompt;
		sigaction(SIGINT, &act, NULL);
	}
	else if (type == EXEC_CHILD)
	{
		default_sigquit();
		act.sa_handler = &exec_interrupt;
		sigaction(SIGINT, &act, NULL);
	}
	else if (type == HEREDOC || type == WAITING_PARENT)
		handle_heredoc(type);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:12:31 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 20:26:08 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>
#include <unistd.h>

void	ignore_sigquit(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}

void	default_sigquit(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_DFL;
	sigaction(SIGQUIT, &act, NULL);
}

void	signal_reset_prompt(int signo)
{
	g_status = 128 + signo;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	exec_interrupt(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_status = 128 + sig;
	}
}

void	signal_ctlc_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		close(STDIN_FILENO);
		g_status = 128 + sig;
	}
}

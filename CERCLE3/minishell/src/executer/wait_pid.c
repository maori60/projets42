/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:32:48 by napham            #+#    #+#             */
/*   Updated: 2024/12/20 20:40:40 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	exec_waitpid(int last_pid)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (waitpid(last_pid, &status, 0) != -1 || errno != ECHILD)
	{
		if (WIFSIGNALED(status) != 0)
		{
			if (!isatty(STDOUT_FILENO))
				return (WTERMSIG(status) + 128);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
			if (WTERMSIG(status) == SIGPIPE)
				ft_fprintf(1, "\n");
			else if (WTERMSIG(status) == SIGQUIT)
				ft_fprintf(1, "Quit: 3\n");
			else if (WTERMSIG(status) == SIGINT)
				ft_fprintf(1, "\n");
			return (WTERMSIG(status) + 128);
		}
		else if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (0);
}

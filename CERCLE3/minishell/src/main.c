/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:40:58 by napham            #+#    #+#             */
/*   Updated: 2024/12/21 00:26:36 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <linux/limits.h>
#include <readline/readline.h>

int	g_status;

static int	parse_n_run(char *line, t_shell *shell)
{
	char	*end_of_input;

	shell->parsed_tree = parse_cmd(line, &end_of_input);
	if (!shell->parsed_tree)
	{
		free(line);
		return (g_status);
	}
	if (look_for_token(&end_of_input, line + ft_strlen(line)) != END_TOKEN)
	{
		g_status = 2;
		write_to_stderr("Syntax Error: Unexpected token");
		free_cmd_tree(shell->parsed_tree);
		free(line);
		return (g_status);
	}
	g_status = run_cmd(shell->parsed_tree, shell);
	free_cmd_tree(shell->parsed_tree);
	free(line);
	return (g_status);
}

static int	routine(t_shell *shell)
{
	char	*line;

	signal_handle(SHELL_PARENT);
	line = readline("minishell> ");
	if (!line)
		return (-42);
	if (ft_strlen(line) > 0)
		add_history(line);
	return (parse_n_run(line, shell));
}

int	main(int argc, char const *argv[], char *env[])
{
	t_shell			shell;

	(void)argv;
	if (argc >= 2)
		ft_print_error("minishell: usage: ./minishell ", 1);
	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
		ft_print_error ("minishell can not interprete script", 1);
	init_env_shell(env, &shell);
	g_status = 0;
	while (g_status > -1)
		if (routine(&shell) == -42)
			break ;
	ft_exit(NULL, 1, &shell);
	return (g_status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:47:20 by napham            #+#    #+#             */
/*   Updated: 2024/12/21 01:46:19 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	arg_is_digit(char *argv)
{
	int	i;

	i = 0;
	if (ft_issign(argv[i]) && ft_strlen(argv) == 1)
		return (0);
	if (ft_issign(argv[i]))
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	less_20_digit(char *argv)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (ft_issign(argv[i]))
		i++;
	while (argv[i] == '0')
		i++;
	while (argv[i])
	{
		n++;
		i++;
	}
	if (n > 20)
		return (0);
	return (1);
}

static int	ft_a_to_exit_code(const char *str)
{
	unsigned long long	res;
	long				i;
	long				sign;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (str[i++] && ft_isdigit(str[i - 1]))
		res = res * 10 + (str[i - 1] - '0');
	if (res > (unsigned long long)LLONG_MAX + 2
		|| (sign == 1 && res > LLONG_MAX))
		return (-1);
	if (sign == -1)
		return (256 - (res % 256));
	else
		return (res % 256);
}

void	safe_exit(char **cmd, t_shell *shell)
{
	if (cmd)
		free_cmd_tree(shell->parsed_tree);
	free_env(shell);
	exit(g_status);
}

/*exit: exit [n]
    Exit the shell.
    
    Exits the shell with a status of N.  If N is omitted, the exit status
    is that of the last command executed.
*/

int	ft_exit(char **cmd, int len, t_shell *shell)
{
	int	n;

	ft_fprintf(2, "exit\n");
	if (len >= 2)
	{
		n = ft_a_to_exit_code(cmd[1]);
		if (!arg_is_digit(cmd[1]) || !less_20_digit(cmd[1]) || n == -1)
		{
			g_status = 2;
			ft_fprintf(2, CD_ERR_NUM_REQUI, cmd[1]);
		}
		else if (len == 2)
			g_status = n;
		else
		{
			ft_putendl_fd("minishell: exit: too many arguments", 2);
			return (1);
		}
	}
	safe_exit(cmd, shell);
	return (0);
}

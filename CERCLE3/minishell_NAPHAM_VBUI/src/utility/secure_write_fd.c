/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_write_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:56:28 by vbui              #+#    #+#             */
/*   Updated: 2024/12/10 10:24:24 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	secure_write_fd(int fd, char *str)
{
	if (str == NULL)
		return (EXIT_SUCCESS);
	while (*str != '\0')
	{
		if (write(fd, str, 1) == -1)
		{
			perror("write error");
			return (EXIT_FAILURE);
		}
		str++;
	}
	return (EXIT_SUCCESS);
}

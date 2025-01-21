/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:25:04 by vbui              #+#    #+#             */
/*   Updated: 2024/02/16 16:18:00 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	if (read(fd, NULL, 0) == -1)
		return (free(left_str), NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(left_str);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || !BUFFER_SIZE)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("toto.txt", O_RDONLY);
	i = 1;
	while (1)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		if(line == NULL)
			break;
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:21:35 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 17:56:41 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*sdup(const char *str, int n)
{
	char	*dest;
	int		i;

	i = -1;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	while (++i < n)
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

static int	count(const char *s, char c)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (s[i - 1])
	{
		if ((s[i] == c || s[i] == 0) && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

static void	ft_free_split(char **cmd)
{
	int	i;

	i = 0;
	while (cmd && cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	if (cmd)
		free(cmd);
}

char	**ft_split(const char *s, char c)
{
	char		**strings;
	size_t		len;
	size_t		i;
	size_t		j;

	strings = ft_calloc(count(s, c) + 1, sizeof(char *));
	len = 0;
	j = -1;
	i = -1;
	while (++j < ft_strlen(s) + 1)
	{
		if (s[j] != c && s[j] != 0)
			len++;
		if (len && (s[j] == c || s[j] == 0))
		{
			strings[++i] = sdup(&s[j] - len, len);
			if (!strings[i])
			{
				ft_free_split(strings);
				return (0);
			}
			len = 0;
		}
	}
	return (strings);
}

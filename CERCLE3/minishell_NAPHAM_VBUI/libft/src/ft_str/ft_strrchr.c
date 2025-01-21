/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:56:06 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 18:00:31 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ptr2;
	int		i;

	ptr = (char *)s;
	ptr2 = 0;
	i = 0;
	c = (unsigned char) c;
	while (*(ptr + i))
	{
		if (*(ptr + i) == c)
			ptr2 = ptr + i;
		i++;
	}
	if (c == '\0')
		return (ptr + i);
	return (ptr2);
}

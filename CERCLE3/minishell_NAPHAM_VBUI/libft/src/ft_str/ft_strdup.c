/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:06:19 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 13:36:34 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* The  strdup()  function returns a pointer to a new string which is a 
duplicate of the string s.  Memory for the new string is ob‐
       tained with malloc(3), and can be freed with free(3). */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*str;

	len = ft_strlen(s);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (0);
	str = ft_memcpy(str, s, len + 1);
	return (str);
}

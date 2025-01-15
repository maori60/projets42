/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:01:17 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 16:57:56 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.                */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sptr;
	int		index;

	if (!s || !f)
		return (NULL);
	sptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sptr)
		return (NULL);
	index = 0;
	while (s[index])
	{
		sptr[index] = f(index, s[index]);
		++index;
	}
	sptr[index] = '\0';
	return (sptr);
}

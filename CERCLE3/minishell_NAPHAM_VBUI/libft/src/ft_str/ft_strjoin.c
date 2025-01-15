/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:36:23 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 13:52:15 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(i + j + 1);
	if (!str)
		return (0);
	j = -1;
	while (s1 && s1[++j])
		str[j] = s1[j];
	j = -1;
	while (s2 && s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:44:36 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 14:44:43 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strlowcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ft_tolower(str[i]);
	return (str);
}

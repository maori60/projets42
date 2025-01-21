/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:43:40 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 14:10:51 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function to return a pointer of the first occurence in a str if
// it belongs to a charset

char	*ft_strchrset(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_strchr(charset, str[i]))
			return (&str[i]);
		i++;
	}
	return (NULL);
}

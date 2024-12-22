/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:48:15 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 13:52:17 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	dest2 = dest;
	src2 = (char *)src;
	if (src2 < dest2)
	{
		dest2 += n - 1;
		src2 += n - 1;
		while (n--)
		{
			*dest2 = *src2;
			dest2--;
			src2--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

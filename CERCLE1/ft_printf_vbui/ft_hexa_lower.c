/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_lower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 01:17:38 by vbui              #+#    #+#             */
/*   Updated: 2024/02/27 01:47:48 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexa_lower(const unsigned int n)
{
	if (n / 16)
		return (ft_hexa_lower(n / 16) + ft_hexa_lower(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar((char) n - 10 + 'a');
	return (1);
}

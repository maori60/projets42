/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:20:11 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 16:00:03 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_dec(int nbr)
{
	unsigned long long	u;
	int					len;

	len = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		len++;
		u = -(unsigned)nbr;
	}
	else
		u = nbr;
	len += ft_putnum(u, 10, "0123456789");
	return (len);
}

int	ft_print_hex_lower(unsigned int nbr)
{
	int	len;

	len = 0;
	len += ft_putnum(nbr, 16, "0123456789abcdef");
	return (len);
}

int	ft_print_hex_upper(unsigned int nbr)
{
	int	len;

	len = 0;
	len += ft_putnum(nbr, 16, "0123456789ABCDEF");
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int	len;

	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	len = 0;
	len += write(1, "0x", 2);
	len += ft_putnum((unsigned long long)ptr, 16, "0123456789abcdef");
	return (len);
}

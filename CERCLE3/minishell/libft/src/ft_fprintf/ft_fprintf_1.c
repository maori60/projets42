/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:20:11 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 14:29:38 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_fprint_char(int fd, int c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_fprint_dec(int fd, int nbr)
{
	unsigned long long	u;
	int					len;

	len = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		len++;
		u = -(unsigned)nbr;
	}
	else
		u = nbr;
	len += ft_fputnum(fd, u, 10, "0123456789");
	return (len);
}

int	ft_fprint_hex_lower(int fd, unsigned int nbr)
{
	int	len;

	len = 0;
	len += ft_fputnum(fd, nbr, 16, "0123456789abcdef");
	return (len);
}

int	ft_fprint_hex_upper(int fd, unsigned int nbr)
{
	int	len;

	len = 0;
	len += ft_fputnum(fd, nbr, 16, "0123456789ABCDEF");
	return (len);
}

int	ft_fprint_ptr(int fd, void *ptr)
{
	int	len;

	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	len = 0;
	len += write(fd, "0x", 2);
	len += ft_fputnum(fd, (unsigned long long)ptr, 16, "0123456789abcdef");
	return (len);
}

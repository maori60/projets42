/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:33:57 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 14:29:35 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_fprint_str(int fd, char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	while (*s)
	{
		ft_putchar_fd(*s++, fd);
		len++;
	}
	return (len);
}

int	ft_fprint_uint(int fd, unsigned int nbr)
{
	int	len;

	len = 0;
	len += ft_fputnum(fd, nbr, 10, "0123456789");
	return (len);
}

int	ft_fprintpercent(int fd)
{
	write(fd, "%", 1);
	return (1);
}

int	ft_fputnum(int fd, unsigned long long n, unsigned int base,
	const char *digits)
{
	int	res;

	res = 1;
	if (n >= base)
		res += ft_fputnum(fd, n / base, base, digits);
	ft_putchar_fd(digits[n % base], fd);
	return (res);
}

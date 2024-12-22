/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:11:46 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 17:25:52 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_fformats(int fd, va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_fprint_char(fd, va_arg(args, int));
	else if (format == 's')
		len += ft_fprint_str(fd, va_arg(args, char *));
	else if (format == 'p')
		len += ft_fprint_ptr(fd, va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_fprint_dec(fd, va_arg(args, int));
	else if (format == 'u')
		len += ft_fprint_uint(fd, va_arg(args, unsigned int));
	else if (format == 'x' )
		len += ft_fprint_hex_lower(fd, va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_fprint_hex_upper(fd, va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_fprintpercent(fd);
	return (len);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_fformats(fd, args, str[i + 1]);
			i++;
		}
		else
			len += ft_fprint_char(fd, str[i]);
		i++;
	}
	va_end(args);
	return (len / len);
}

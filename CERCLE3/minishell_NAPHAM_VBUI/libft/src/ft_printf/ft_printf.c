/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:11:46 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 15:58:30 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_print_dec(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'x' )
		len += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_printpercent();
	return (len);
}

int	ft_printf(const char *str, ...)
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
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

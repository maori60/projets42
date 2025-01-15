/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 01:17:00 by vbui              #+#    #+#             */
/*   Updated: 2024/02/28 01:15:47 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	process_format(const char *c, size_t *i, va_list *ap)
{
	*i = *i + 1;
	if (*(c + 1) == 'c')
		return (ft_putchar((char) va_arg(*ap, int)));
	else if (*(c + 1) == 's')
		return (ft_putstr(va_arg(*ap, const char *)));
	else if (*(c + 1) == 'p')
		return (ft_putadress(va_arg(*ap, void *)));
	else if (*(c + 1) == 'd' || *(c + 1) == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (*(c + 1) == 'u')
		return (ft_putunbr(va_arg(*ap, unsigned int)));
	else if (*(c + 1) == 'x')
		return (ft_hexa_lower(va_arg(*ap, int)));
	else if (*(c + 1) == 'X')
		return (ft_hexa_upper(va_arg(*ap, int)));
	else if (*(c + 1) == '%')
		return (ft_putchar('%'));
	else if (*(c + 1) && *(c + 2))
		return (ft_putchar(*(c)) + ft_putchar(*(c + 1)));
	else
	{
		*i -= 1;
		return (-1);
	}
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		tmp;
	va_list	ap;
	size_t	i;

	if (!str)
		return (-1);
	len = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			tmp = process_format(str + i, &i, &ap);
		else
			tmp = ft_putchar(str[i]);
		if (tmp >= 0)
			len += tmp;
		else
			len = tmp;
		i++;
	}
	va_end(ap);
	return (len);
}
/*
#include "ft_printf.h"
#include <stdio.h>

int main() {
    // Test simple string
    ft_printf("Hello\n");
	printf("Hello\n");

    // Test avec des caractères
    char c = 'A';
    ft_printf("Caractere de l'avatar: %c\n", c);
	printf("Caractere: %c\n", c);

    // Test avec des chaînes de caractères
    char *str = "Sample string";
    ft_printf("chaine de caractere de l'avatar : %s\n", str);
	printf("chaine de caractere de l'avatar: %s\n", str);

    // Test avec des nombres entiers
    int num = 42;
    ft_printf("Entier de l'avatar: %d\n", num);
	printf("Entier: %d\n", num);

    // Test avec un nombre hexadécimal
    ft_printf("Hexadecimal de l'avatar: %x\n", num);
	printf("Hexadecimal: %x\n", num);

    // Test pour voir le comportement avec NULL
    ft_printf(NULL);
	printf(NULL);

    return 0;
}
*/
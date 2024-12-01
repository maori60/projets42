/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_store.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:14:27 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:48 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_get_size(t_struct *strt, int *i, char *format)
{
	unsigned int	tmp;

	tmp = strt->size;
	if (format[*i] == 'h' && format[*i + 1] == 'h')
		tmp = HH;
	else if (format[*i] == 'h')
		tmp = H;
	else if (format[*i] == 'l' && format[*i + 1] == 'l')
		tmp = LL;
	else if (format[*i] == 'l')
		tmp = L;
	else if (format[*i] == 'j')
		tmp = J;
	else if (format[*i] == 'z')
		tmp = Z;
	else if (format[*i] == 't')
		tmp = T;
	if (tmp > strt->size)
		strt->size = tmp;
}

static void		ft_get_flags(t_struct *strt, int *i, char *format)
{
	if (format[*i] == '#')
		strt->flag[0] = 1;
	else if (format[*i] == '0')
		strt->flag[1] = 1;
	else if (format[*i] == '-')
		strt->flag[2] = 1;
	else if (format[*i] == '+')
		strt->flag[3] = 1;
	else if (format[*i] == ' ')
		strt->flag[4] = 1;
}

static void		ft_just_cuz_its_too_long(t_struct *strt, char *format, int *i)
{
	if (!ft_isdigit(format[*i + 1]))
		strt->prec = 0;
	else
	{
		*i += 1;
		strt->prec = ft_atoi(format + *i);
		strt->prec == 0 ? *i += 0 : (*i += ft_digitlen(strt->prec) - 1);
	}
}

char			*ft_parse_and_store(t_struct *strt, char *format)
{
	int i;

	i = 0;
	while (!strt->type && format[i++] != '\0')
	{
		if (ft_strchr("#0-+ ", format[i]) && format[i + 1] != '\0')
			ft_get_flags(strt, &i, format);
		else if (format[i] >= '1' && format[i] <= '9' && format[i + 1] != '\0')
		{
			strt->width = ft_atoi(format + i);
			i += ft_digitlen(strt->width) - 1;
		}
		else if (format[i] == '.')
			ft_just_cuz_its_too_long(strt, format, &i);
		else if (ft_strchr("hljztLq", format[i]) && format[i + 1] != '\0')
			ft_get_size(strt, &i, format);
		else if (ft_strchr("sSpdiDoOuUxXcCeEfFgGaAnm%", format[i]))
			strt->type = format[i];
		else
			return (format + i);
	}
	return (format + i);
}
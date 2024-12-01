/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:27:19 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 19:36:44 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	ft_display(t_struct *strt)
{
	if (strt->s_arg || (strt->type == 'c' && strt->size != L))
	{
		if ((char)strt->arg == 0 && strt->type == 'c'
			&& strt->prec && strt->flag[2])
		{
			strt->oct += ft_putwchar('\0');
			ft_putstr(strt->s_arg);
		}
		else
		{
			ft_putstr(strt->s_arg);
			if ((char)strt->arg == 0 && strt->type == 'c')
				strt->oct += ft_putwchar('\0');
		}
		strt->oct += ft_strlen(strt->s_arg);
	}
	else if (strt->ws_arg)
	{
		ft_putwstr(strt->ws_arg);
		strt->oct += ft_wstrlen(strt->ws_arg);
		if ((wchar_t)strt->arg == 0 && (strt->type == 'C' || strt->size == L))
			strt->oct += ft_putwchar('\0');
	}
}

static void	ft_typedefiner(t_struct *strt)
{
	if (strt->type == 's' || strt->type == 'S')
		ft_for_s(strt);
	else if (strt->type == 'p')
		ft_for_p(strt);
	else if (strt->type == 'd' || strt->type == 'i' || strt->type == 'D')
		ft_for_d_and_i(strt);
	else if (strt->type == 'o' || strt->type == 'O')
		ft_for_o(strt);
	else if (strt->type == 'u' || strt->type == 'U')
		ft_for_u(strt);
	else if (strt->type == 'x' || strt->type == 'X')
		ft_for_x(strt);
	else if (strt->type == 'c' || strt->type == 'C')
		ft_for_c(strt);
	else if (strt->type == '%')
		ft_for_pct(strt);
}

static char	*ft_typefinder(char *format, t_struct *strt, int *i)
{
	format = ft_parse_and_store(strt, format);
	if (strt->type != 0)
	{
		ft_get_arg(strt);
		ft_typedefiner(strt);
	}
	if (!strt->type)
		ft_bad_parse(strt, format);
	ft_display(strt);
	ft_initialise(strt);
	*i = 0;
	return (format);
}

int	ft_printf(char *format, ...)
{
	t_struct	strt;
	int			i;

	i = -1;
	ft_first(&strt);
	va_start(strt.ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				format = ft_typefinder(format + i, &strt, &i);
		}
		else if (format[i] != '\0')
			strt.oct += ft_putwchar(format[i]);
		if (strt.err < 0)
		{
			strt.oct = -1;
			break ;
		}
	}
	va_end(strt.ap);
	return (strt.oct);
}

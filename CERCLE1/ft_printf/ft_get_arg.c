/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:14:03 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:50 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_if_nega(t_struct *strt)
{
	strt->arg = -strt->arg;
	strt->nega = 1;
}

static void		ft_get_arg2(t_struct *strt)
{
	if (strt->type == 'o' || strt->type == 'O'
			|| strt->type == 'u' || strt->type == 'U'
			|| strt->type == 'x' || strt->type == 'X')
	{
		if (strt->size == L || strt->type == 'O'
				|| strt->type == 'U' || strt->type == 'X')
			strt->arg = (unsigned long)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == H)
			strt->arg = (unsigned short)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == HH)
			strt->arg = (unsigned char)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == LL)
			strt->arg = (unsigned long long)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == J)
			strt->arg = (uintmax_t)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == Z)
			strt->arg = (size_t)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == T)
			strt->arg = (ptrdiff_t)va_arg(strt->ap, uintmax_t *);
		else
			strt->arg = (unsigned int)va_arg(strt->ap, uintmax_t *);
	}
}

static void		ft_get_arg1(t_struct *strt)
{
	if (strt->type == 'd' || strt->type == 'i' || strt->type == 'D')
	{
		if (strt->size == L || strt->type == 'D')
			strt->arg = (long)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == H)
			strt->arg = (short)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == HH)
			strt->arg = (signed char)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == LL)
			strt->arg = (long long)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == J)
			strt->arg = (intmax_t)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == Z)
			strt->arg = (ssize_t)va_arg(strt->ap, uintmax_t *);
		else if (strt->size == T)
			strt->arg = (ptrdiff_t)va_arg(strt->ap, uintmax_t *);
		else
			strt->arg = (int)va_arg(strt->ap, uintmax_t *);
		if (strt->arg < 0)
			ft_if_nega(strt);
	}
	else
		ft_get_arg2(strt);
}

void			ft_get_arg(t_struct *strt)
{
	if (strt->type == 's' || strt->type == 'S')
	{
		if (strt->size == L || strt->type == 'S')
			strt->arg = (uintmax_t)va_arg(strt->ap, wchar_t *);
		else
			strt->arg = (uintmax_t)va_arg(strt->ap, char *);
	}
	else if (strt->type == 'p')
		strt->arg = (uintmax_t)va_arg(strt->ap, void *);
	else if (strt->type == 'c' || strt->type == 'C')
	{
		if (strt->size == L || strt->type == 'C')
			strt->arg = (wchar_t)va_arg(strt->ap, uintmax_t);
		else
			strt->arg = (char)va_arg(strt->ap, uintmax_t);
	}
	else if (strt->type == '%')
		strt->arg = '%';
	else
		ft_get_arg1(strt);
}
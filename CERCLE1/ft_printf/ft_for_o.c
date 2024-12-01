/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:12:54 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:58 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_flags(t_struct *strt)
{
	char	*tmps;
	char	*tmpsarg;

	if (*strt->s_arg != '0')
	{
		strt->l_arg = ft_strlen(strt->s_arg);
		tmps = ft_strnew(1);
		ft_strncpy(tmps, "0", 1);
		tmpsarg = ft_strnew(strt->l_arg);
		ft_strcpy(tmpsarg, strt->s_arg);
		ft_strjoinfree(tmps, tmpsarg, strt, 0);
	}
}

static void		ft_width(t_struct *strt)
{
	char	*tmps;
	char	*tmpsarg;
	char	c;

	strt->l_arg = ft_strlen(strt->s_arg);
	if (strt->width > strt->l_arg)
	{
		c = ' ';
		if (strt->flag[1] && !strt->flag[2] && strt->prec < 0)
			c = '0';
		tmps = ft_strnew(strt->width - strt->l_arg);
		ft_memset(tmps, c, strt->width - strt->l_arg);
		tmpsarg = ft_strnew(strt->l_arg);
		ft_strcpy(tmpsarg, strt->s_arg);
		ft_strjoinfree(tmps, tmpsarg, strt, strt->flag[2]);
	}
}

static void		ft_prec(t_struct *strt)
{
	char	*tmps;
	char	*tmpsarg;

	tmpsarg = ft_strnew(strt->l_arg + 1);
	(strt->prec == 0 && strt->arg == 0) ?
		(ft_strcpy(strt->s_arg, " ")) : ft_strcpy(tmpsarg, strt->s_arg);
	tmps = ft_strnew(strt->prec + 1);
	if (strt->prec > strt->l_arg)
		ft_memset(tmps, '0', strt->prec - strt->l_arg);
	ft_strjoinfree(tmps, tmpsarg, strt, 0);
}

void			ft_for_o(t_struct *strt)
{
	if (strt->size == L || strt->type == 'O')
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 8, "01234567");
	else if (strt->size == H)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 8, "01234567");
	else if (strt->size == HH)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 8, "01234567");
	else if (strt->size == LL)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 8, "01234567");
	else if (strt->size == J)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 8, "01234567");
	else if (strt->size == Z)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 8, "01234567");
	else if (strt->size == T)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 8, "01234567");
	else
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 8, "01234567");
	strt->l_arg = ft_strlen(strt->s_arg);
	if (strt->prec >= 0 || (strt->width && strt->prec < 0 && strt->flag[1]))
		ft_prec(strt);
	if (strt->flag[0])
		ft_flags(strt);
	if (strt->width)
		ft_width(strt);
}
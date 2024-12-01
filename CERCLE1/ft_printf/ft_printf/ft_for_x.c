/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:13:51 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:52 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_flags(t_struct *strt)
{
	char	*tmps;
	char	*tmpsarg;

	if (strt->arg != 0)
	{
		if (strt->width && strt->prec < 0 && strt->flag[1] && !strt->flag[2])
		{
			strt->prec = strt->width;
			strt->width = 0;
			tmpsarg = ft_strnew(strt->l_arg);
			ft_strcpy(tmpsarg, strt->s_arg);
			tmps = ft_strnew(strt->l_arg + 1);
			ft_memset(tmps, '0', strt->prec - strt->l_arg - 2);
			ft_strjoinfree(tmps, tmpsarg, strt, 0);
		}
		strt->l_arg = ft_strlen(strt->s_arg);
		tmps = ft_strnew(2);
		ft_strncpy(tmps, "0x", 2);
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
	(strt->prec == 0 && strt->arg == 0) ? (ft_strcpy(tmpsarg, " ")) :
		ft_strcpy(tmpsarg, strt->s_arg);
	if (strt->prec == 0 && strt->arg == 0)
		ft_bzero(tmpsarg, 1);
	tmps = ft_strnew(strt->prec + 1);
	if (strt->prec > strt->l_arg)
		ft_memset(tmps, '0', strt->prec - strt->l_arg);
	ft_strjoinfree(tmps, tmpsarg, strt, 0);
}

static void		ft_for_x2(t_struct *strt)
{
	strt->l_arg = ft_strlen(strt->s_arg);
	if (strt->prec >= 0 || (strt->width && strt->prec < 0 && strt->flag[1]))
		ft_prec(strt);
	if (strt->flag[0])
		ft_flags(strt);
	if (strt->width > strt->l_arg)
		ft_width(strt);
	if (strt->type == 'X')
		strt->s_arg = ft_strcapitalize(strt->s_arg);
}

void			ft_for_x(t_struct *strt)
{
	if (strt->size == L)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 16, "0123456789abcdef");
	else if (strt->size == H)
		strt->s_arg =
		ft_itoa_base_unsi((unsigned short)strt->arg, 16, "0123456789abcdef");
	else if (strt->size == HH)
		strt->s_arg =
			ft_itoa_base_unsi((unsigned char)strt->arg, 16, "0123456789abcdef");
	else if (strt->size == LL)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 16, "0123456789abcdef");
	else if (strt->size == J)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 16, "0123456789abcdef");
	else if (strt->size == Z)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 16, "0123456789abcdef");
	else if (strt->size == T)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 16, "0123456789abcdef");
	else
		strt->s_arg = ft_itoa_base_unsi((unsigned int)strt->arg,
			16, "0123456789abcdef");
	ft_for_x2(strt);
}
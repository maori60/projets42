/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_d_and_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:12:38 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:59 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_flags(t_struct *strt)
{
	char	*tmps;
	char	*tmpsarg;

	tmpsarg = ft_strnew(strt->l_arg);
	ft_strcpy(tmpsarg, strt->s_arg);
	tmps = ft_strnew(strt->l_arg + 1);
	if (strt->width && strt->prec < 0 && strt->flag[1] && !strt->flag[2])
	{
		strt->prec = strt->width;
		strt->width = 0;
		tmps = ft_strnew(strt->l_arg + 1);
		if (strt->prec > strt->l_arg)
			ft_memset(tmps, '0', strt->prec - strt->l_arg);
	}
	if (strt->flag[3] == 1)
		ft_memset(tmps, '+', 1);
	else if (strt->flag[4] == 1)
		ft_memset(tmps, ' ', 1);
	ft_strjoinfree(tmps, tmpsarg, strt, 0);
}

static void		ft_width2(t_struct *strt, char **tmps, char **tmpsarg, char *c)
{
	if (strt->flag[1] && !strt->flag[2] &&
			strt->prec < 0 && !strt->flag[0])
		*c = '0';
	if (strt->nega)
		strt->l_arg += 1;
	if (strt->nega && *c == ' ')
	{
		*tmps = ft_strnew(1);
		ft_memset(*tmps, '-', 1);
		*tmpsarg = ft_strnew(strt->l_arg);
		ft_strcpy(*tmpsarg, strt->s_arg);
		ft_strjoinfree(*tmps, *tmpsarg, strt, 0);
		strt->nega = 0;
	}
	*tmps = ft_strnew(strt->width - strt->l_arg);
	ft_memset(*tmps, *c, strt->width - strt->l_arg);
	*tmpsarg = ft_strnew(strt->l_arg);
	ft_strcpy(*tmpsarg, strt->s_arg);
	ft_strjoinfree(*tmps, *tmpsarg, strt, strt->flag[2]);
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
		ft_width2(strt, &tmps, &tmpsarg, &c);
	}
	if (strt->nega)
	{
		tmps = ft_strnew(1);
		ft_memset(tmps, '-', 1);
		tmpsarg = ft_strnew(strt->l_arg);
		ft_strcpy(tmpsarg, strt->s_arg);
		ft_strjoinfree(tmps, tmpsarg, strt, 0);
	}
}

static void		ft_prec(t_struct *strt)
{
	char	*tmps;
	char	*tmpsarg;

	tmpsarg = ft_strnew(strt->l_arg);
	tmps = ft_strnew(strt->prec + 1);
	if (strt->prec > strt->l_arg)
		ft_memset(tmps, '0', strt->prec - strt->l_arg);
	if (strt->nega == 1)
		ft_strcpy(tmpsarg, strt->s_arg);
	else
	{
		if (!strt->prec && !strt->arg && strt->width)
			ft_strcpy(tmpsarg, " ");
		else if (!strt->prec && !strt->arg)
			ft_strcpy(tmpsarg, "");
		else
			ft_strcpy(tmpsarg, strt->s_arg);
	}
	ft_strjoinfree(tmps, tmpsarg, strt, 0);
}

void			ft_for_d_and_i(t_struct *strt)
{
	if (strt->size == L || strt->type == 'D')
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == H)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == HH)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == LL)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == J)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == Z)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == T)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else
		strt->s_arg =
			ft_itoa_base_unsi((unsigned int)strt->arg, 10, "0123456789");
	strt->l_arg = ft_strlen(strt->s_arg);
	if (strt->prec >= 0)
		ft_prec(strt);
	if (!strt->nega && (strt->flag[4] || strt->flag[3] || strt->flag[2]))
		ft_flags(strt);
	if (strt->width > strt->l_arg || strt->nega)
		ft_width(strt);
}
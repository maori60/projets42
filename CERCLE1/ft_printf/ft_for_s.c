/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:13:29 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:54 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_printf.h"

static void		ft_width_and_flags2(t_struct *strt, int len, char c)
{
	wchar_t *tmpws;
	wchar_t	*tmpwsarg;
	int		i;

	i = 0;
	tmpws = ft_wstrnew(strt->width);
	while (len > 0)
	{
		if (strt->flag[1] && !strt->flag[2])
			c = '0';
		tmpws[i++] = c;
		len--;
	}
	tmpws[i] = '\0';
	tmpwsarg = ft_wstrnew(strt->prec + 1);
	ft_wstrcpy(tmpwsarg, strt->ws_arg);
	ft_wstrjoinfree(tmpws, tmpwsarg, strt, strt->flag[2]);
}

static void		ft_width_and_flags(t_struct *strt)
{
	char	*tmpsarg;
	char	*tmps;
	int		len;
	int		i;
	char	c;

	c = ' ';
	i = 0;
	len = 0;
	if (strt->width > strt->prec)
		len = strt->width - strt->prec;
	if (strt->type == 's' && strt->size != L)
	{
		tmps = ft_strnew(strt->width);
		if (strt->flag[1] && !strt->flag[2])
			c = '0';
		ft_memset(tmps, c, len);
		tmpsarg = ft_strnew(strt->prec);
		ft_strcpy(tmpsarg, strt->s_arg);
		ft_strjoinfree(tmps, tmpsarg, strt, strt->flag[2]);
	}
	else
		ft_width_and_flags2(strt, len, c);
}

static void		ft_for_s2(t_struct *strt)
{
	if (strt->type == 's' && strt->size != L)
	{
		!(char *)strt->arg ? strt->l_arg = 6 :
			(strt->l_arg = ft_strlen((char *)strt->arg));
		strt->s_arg = ft_strnew(strt->l_arg);
		if (strt->prec > strt->l_arg || strt->prec < 0)
			strt->prec = strt->l_arg;
		if ((char *)strt->arg)
			ft_strncpy(strt->s_arg, (char *)strt->arg, strt->prec);
		else
			ft_strncpy(strt->s_arg, "(null)", strt->prec);
	}
	if (strt->width)
		ft_width_and_flags(strt);
}

static void		ft_ls_or_bigs(wchar_t **tmpw, intmax_t *tmpprec, t_struct *strt)
{
	(wchar_t *)strt->arg ? (*tmpw = (wchar_t *)strt->arg) :
		(*tmpw = L"(null)");
	!(wchar_t *)strt->arg ? (strt->l_arg = 6) :
		(strt->l_arg = ft_wstrlen(*tmpw));
	if (strt->prec > strt->l_arg || strt->prec < 0)
		strt->prec = strt->l_arg;
	*tmpprec = strt->prec;
	strt->ws_arg = ft_wstrnew(strt->l_arg);
}

void			ft_for_s(t_struct *strt)
{
	wchar_t			*tmpw;
	intmax_t		i;
	intmax_t		tmpprec;

	i = 0;
	if (strt->size == L || strt->type == 'S')
	{
		ft_ls_or_bigs(&tmpw, &tmpprec, strt);
		while (*tmpw && (tmpprec -= ft_wcharlen(*tmpw)) >= 0)
		{
			if ((int)ft_wcharlen(*tmpw) < 0 ||
					(int)ft_wcharlen(*tmpw) > MB_CUR_MAX)
			{
				free(strt->ws_arg);
				strt->ws_arg = NULL;
				strt->err = -1;
				return ;
			}
			(ft_wcharlen(*tmpw) == 1) ? (strt->ws_arg[i++] = (char)*tmpw++) :
				(strt->ws_arg[i++] = *tmpw++);
		}
		strt->ws_arg[i] = '\0';
		strt->prec = ft_wstrlen(strt->ws_arg);
	}
	ft_for_s2(strt);
}
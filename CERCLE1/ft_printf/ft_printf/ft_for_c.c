/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:12:10 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:20:00 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_width_and_flags2(t_struct *strt, char c)
{
	wchar_t *tmpws;
	wchar_t	*tmpwsarg;
	int		len;
	int		i;

	len = strt->width - ft_wcharlen(*strt->ws_arg);
	i = 0;
	tmpws = ft_wstrnew(len + 1);
	if (strt->flag[1] && !strt->flag[2])
		c = '0';
	while (len > 0)
	{
		tmpws[i++] = c;
		len--;
	}
	tmpws[i] = '\0';
	tmpwsarg = ft_wstrnew(ft_wcharlen(strt->ws_arg[i]) + 1);
	ft_wstrcpy(tmpwsarg, strt->ws_arg);
	ft_wstrjoinfree(tmpws, tmpwsarg, strt, strt->flag[2]);
	if (*strt->ws_arg == 0)
		strt->oct += ft_putwchar('\0');
}

static void		ft_width_and_flags(t_struct *strt)
{
	char	*tmpsarg;
	char	*tmps;
	char	c;

	c = ' ';
	if (strt->type == 'c' && strt->size != L)
	{
		tmps = ft_strnew(strt->width);
		if (strt->flag[1] && !strt->flag[2])
			c = '0';
		if (strt->width)
			ft_memset(tmps, c, strt->width - 1);
		tmpsarg = ft_strnew(2);
		ft_strncpy(tmpsarg, strt->s_arg, 1);
		ft_strjoinfree(tmps, tmpsarg, strt, strt->flag[2]);
	}
	else
		ft_width_and_flags2(strt, c);
}

void			ft_for_c(t_struct *strt)
{
	int	len;

	len = 0;
	if (strt->size == L || strt->type == 'C')
	{
		len = (int)ft_wcharlen((wchar_t)strt->arg);
		if (len > MB_CUR_MAX || len < 0 || strt->arg < 0)
		{
			strt->err = -1;
			return ;
		}
		strt->ws_arg = ft_wstrnew(len);
		(len == 1) ? (strt->ws_arg[0] = (char)strt->arg) :
			(strt->ws_arg[0] = (wchar_t)strt->arg);
		strt->ws_arg[1] = '\0';
	}
	else
	{
		strt->s_arg = ft_strnew(2);
		strt->s_arg[0] = (char)strt->arg;
		strt->s_arg[1] = '\0';
	}
	if (strt->width > len)
		ft_width_and_flags(strt);
}
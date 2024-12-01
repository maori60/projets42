/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_pct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:13:17 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:55 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_width_and_flags(t_struct *strt)
{
	char	*tmpsarg;
	char	*tmps;
	char	c;

	c = ' ';
	tmps = ft_strnew(strt->width - 1);
	if (strt->flag[1] && !strt->flag[2])
		c = '0';
	if (strt->width)
		ft_memset(tmps, c, strt->width - 1);
	tmpsarg = ft_strnew(2);
	ft_strncpy(tmpsarg, strt->s_arg, 1);
	ft_strjoinfree(tmps, tmpsarg, strt, strt->flag[2]);
}

void			ft_for_pct(t_struct *strt)
{
	strt->s_arg = ft_strnew(2);
	strt->s_arg[0] = '%';
	strt->s_arg[1] = '\0';
	if (strt->width)
		ft_width_and_flags(strt);
}
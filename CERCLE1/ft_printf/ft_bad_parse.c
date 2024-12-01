/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bad_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:58:02 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:20:02 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_printf.h"

void		ft_bad_parse(t_struct *strt, char *format)
{
	char	*tmpsarg;
	char	*tmps;
	char	c;

	c = ' ';
	tmps = NULL;
	if (!ft_strchr("sSpdiDoOuUxXcCeEfFgGaAnm%hljztLq#0-+ ", *format))
	{
		tmpsarg = ft_strnew(2);
		strt->s_arg = ft_strnew(2);
		strt->s_arg[0] = *format;
		strt->s_arg[1] = '\0';
		if (strt->width && strt->prec <= 0)
		{
			tmps = ft_strnew(strt->width);
			if (strt->flag[1] && !strt->flag[2])
				c = '0';
			ft_memset(tmps, c, strt->width - 1);
		}
		ft_strncpy(tmpsarg, strt->s_arg, 1);
		ft_strjoinfree(tmps, tmpsarg, strt, strt->flag[2]);
	}
}
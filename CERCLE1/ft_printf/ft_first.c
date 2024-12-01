/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:11:47 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:20:01 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void		ft_first(t_struct *strt)
{
	strt->oct = 0;
	strt->s_arg = NULL;
	strt->ws_arg = NULL;
	strt->type = 0;
	strt->err = 0;
	strt->size = 0;
	strt->prec = -1;
	strt->width = 0;
	strt->flag[0] = 0;
	strt->flag[1] = 0;
	strt->flag[2] = 0;
	strt->flag[3] = 0;
	strt->flag[4] = 0;
	strt->nega = 0;
	strt->arg = 0;
	strt->l_arg = 0;
	strt->bad_c = 0;
}
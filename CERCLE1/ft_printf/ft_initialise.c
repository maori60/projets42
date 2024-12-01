/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:14:14 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:49 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_initialise(t_struct *strt)
{
	if (strt->s_arg)
	{
		free(strt->s_arg);
		strt->s_arg = NULL;
	}
	if (strt->ws_arg)
	{
		free(strt->ws_arg);
		strt->ws_arg = NULL;
	}
	strt->type = 0;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:15:03 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:43 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_printf.h"

void	ft_wstrjoinfree(wchar_t *s1, wchar_t *s2, t_struct *strt, int n)
{
	int		len;

	if (!s1 || !s2)
		return ;
	if (strt->ws_arg)
	{
		free(strt->ws_arg);
		strt->ws_arg = NULL;
	}
	len = ft_wstrlen(s1) + ft_wstrlen(s2);
	if (!(strt->ws_arg = (wchar_t *)(malloc(sizeof(wchar_t) * (len + 2)))))
		return ;
	if (n == 0)
	{
		ft_wstrcpy(strt->ws_arg, s1);
		ft_wstrcat(strt->ws_arg, s2);
	}
	else
	{
		ft_wstrcpy(strt->ws_arg, s2);
		ft_wstrcat(strt->ws_arg, s1);
	}
	free(s1);
	free(s2);
}
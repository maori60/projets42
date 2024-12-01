/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:14:50 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:45 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static int		ft_check_free(char *s1, char *s2)
{
	if (!s1)
	{
		if (s2)
		{
			free(s2);
			s2 = NULL;
		}
		return (0);
	}
	else if (!s2)
	{
		if (s1)
		{
			free(s1);
			s1 = NULL;
		}
		return (0);
	}
	return (1);
}

void			ft_strjoinfree(char *s1, char *s2, t_struct *strt, int n)
{
	int		len;

	if (!ft_check_free(s1, s2))
		return ;
	if (strt->s_arg)
		free(strt->s_arg);
	strt->s_arg = NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(strt->s_arg = (char *)(malloc(sizeof(char) * (len + 2)))))
		return ;
	if (n == 0)
	{
		ft_strcpy(strt->s_arg, s1);
		ft_strcat(strt->s_arg, s2);
	}
	else
	{
		ft_strcpy(strt->s_arg, s2);
		ft_strcat(strt->s_arg, s1);
	}
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}
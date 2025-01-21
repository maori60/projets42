/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:53:59 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 16:04:39 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*p;

	if (lst)
	{
		if (*lst)
		{
			p = ft_lstlast(*lst);
			p->next = newlst;
		}
		else
			*lst = newlst;
	}
}

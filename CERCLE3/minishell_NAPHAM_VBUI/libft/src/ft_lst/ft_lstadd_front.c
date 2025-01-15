/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:34:29 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 16:04:09 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Adds the node ’newlst’ at the beginning of the list */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newlst)
{
	if (lst)
	{
		if (*lst)
			newlst->next = *lst;
		*lst = newlst;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:22:43 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 16:09:36 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_print_error(char *desc, int error)
{
	if (desc == NULL)
		return ((void) NULL);
	while (*desc)
		write(2, desc++, 1);
	write(2, "\n", 1);
	exit(error);
}

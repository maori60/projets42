/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:50:01 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 12:06:57 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
 * The calloc() function allocates memory for an array of  nmemb  elements
       of  size bytes each and returns a pointer to the allocated memory.  
	   
	   The memory is set to zero.  
	   If nmemb or size is 0,  then  calloc()  returns
       either  NULL,  or a unique pointer value that can later be successfully
       passed to free().  If the multiplication of nmemb and size would result
       in  integer  overflow, then calloc() returns an error.  By contrast, an
       integer overflow would not be detected in the following  call  to  mal‐
       loc(),  with the result that an incorrectly sized block of memory would
       be allocated:

           malloc(nmemb * size);
**************************************************************************/
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	char	*mem;
	size_t	i;

	total = count * size;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	mem = malloc(total);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

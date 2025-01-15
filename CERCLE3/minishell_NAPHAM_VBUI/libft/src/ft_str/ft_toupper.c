/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:56:37 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 14:22:57 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int character)
{
	if (character >= 'a' && character <= 'z')
		return (character -= 32);
	else
		return (character);
}

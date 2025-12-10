/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:00:00 by van               #+#    #+#             */
/*   Updated: 2025/12/10 18:31:17 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef> // std::size_t

// Version générique : tableau modifiable
template <typename T, typename F>
void	iter(T *array, std::size_t length, F func)
{
	if (!array)
		return;
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

// Version pour tableau constant (facultatif mais propre)
template <typename T, typename F>
void	iter(T const *array, std::size_t length, F func)
{
	if (!array)
		return;
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:01:20 by cgodecke          #+#    #+#             */
/*   Updated: 2025/12/10 18:31:29 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>      // std::toupper
#include "iter.hpp"

void	times_two(int &i)
{
	i *= 2;
}

void	to_upper(std::string &str)
{
	for (std::size_t i = 0; i < str.length(); ++i)
		str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
}

int	main(void)
{
	std::cout << "\033[33m" << "Test int array\n" << "\033[0m";
	int	int_arr[] = {1, 2, 3};

	::iter(int_arr, 3, times_two);
	for (int i = 0; i < 3; ++i)
		std::cout << int_arr[i] << std::endl;

	std::cout << "\033[33m" << "Test string array\n" << "\033[0m";
	std::string	str_arr[] = {"Hello", "World", "!"};

	::iter(str_arr, 3, to_upper);
	for (int i = 0; i < 3; ++i)
		std::cout << str_arr[i] << std::endl;

	return (0);
}

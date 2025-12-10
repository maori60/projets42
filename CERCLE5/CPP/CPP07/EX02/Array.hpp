/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:00:00 by van               #+#    #+#             */
/*   Updated: 2025/12/10 18:33:11 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>   // size_t
# include <exception> // std::exception

template <typename T>
class Array
{
private:
	T*          _data;
	unsigned int _size;

public:
	// Exceptions
	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	// Orthodox Canonical Form
	Array();                        // Default constructor
	Array(unsigned int n);          // Constructor with size
	Array(Array const &other);      // Copy constructor
	~Array();                       // Destructor
	Array &operator=(Array const &other); // Assignment operator

	// Element access
	T&         operator[](unsigned int index);
	T const&   operator[](unsigned int index) const;

	// Size accessor
	unsigned int size() const;
};

# include "Array.tpp"

#endif

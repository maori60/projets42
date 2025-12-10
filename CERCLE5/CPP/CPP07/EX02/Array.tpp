/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:00:00 by van               #+#    #+#             */
/*   Updated: 2025/12/10 18:33:18 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

// ===== Exceptions ========================================================= //

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array index out of bounds";
}

// ===== Constructors / Destructor / Operator= ============================= //

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (n == 0)
	{
		_data = NULL;
	}
	else
	{
		// value-initialize les éléments (0 pour les types built-in)
		_data = new T[n]();
	}
}

template <typename T>
Array<T>::Array(Array const &other) : _data(NULL), _size(0)
{
	_size = other._size;
	if (_size == 0)
	{
		_data = NULL;
	}
	else
	{
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		delete[] _data;

		_size = other._size;
		if (_size == 0)
		{
			_data = NULL;
		}
		else
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
	}
	return *this;
}

// ===== Element access ===================================================== //

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

// ===== Size =============================================================== //

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:52:02 by seoson            #+#    #+#             */
/*   Updated: 2024/01/20 18:36:55 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : t(NULL), Array_size(0)
{
	std::cout << "Default Array Constructor Called" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Default Array Destructor Called" << std::endl;
	delete (this->t);
}

template <typename T>
Array<T>::Array(unsigned int n): Array_size(n)
{
	t = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other)
{
	std::cout << "Array Copy Operator Called" << std::endl;
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	std::cout << "Array Assignment Operator Called" << std::endl;
	if (this == &other)
		return (*this);
	this->Array_size = other.Array_size;
	delete (this->t);
	t = new T[this->Array_size];
	for (size_t i = 0; i < this->Array_size; i++)
		this->t[i] = other.t[i];
	return (*this);
}

template <typename T>
size_t Array<T>::size() const
{
	return (this->Array_size);
}

template <typename T>
T&	Array<T>::operator[](size_t size) const
{
	if (size < 0 || size >= this->Array_size)
		throw(std::exception());
	return (t[size]);
}

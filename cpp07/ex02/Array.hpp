/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:45:20 by seoson            #+#    #+#             */
/*   Updated: 2024/01/19 15:45:31 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T		*t;
		size_t	Array_size;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array&);
		Array&	operator=(const Array&);
		size_t	size() const;
		T&		operator[](size_t size) const;
};

#include "Array.tpp"

#endif

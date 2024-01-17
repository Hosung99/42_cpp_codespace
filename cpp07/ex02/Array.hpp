/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:45:20 by seoson            #+#    #+#             */
/*   Updated: 2024/01/17 22:52:00 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include "Array.tpp"

template <typename T>
class Array
{
	private:
		T t[];
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array&);
		Array& operator=(const Array&);
		size_t	size() const;
};



#endif

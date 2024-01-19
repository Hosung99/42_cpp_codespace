/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:48:31 by seoson            #+#    #+#             */
/*   Updated: 2024/01/19 12:38:59 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T& first,T& second)
{
	T temp;
	temp = first;
	first = second;
	second = temp;
}

template <typename T>
T	min(const T& first,const T second)
{
	if (second <= first)
		return (second);
	return (first);
}

template <typename T>
T	max(const T& first,const T& second)
{
	if (second >= first)
		return (second);
	return (first);
}

#endif

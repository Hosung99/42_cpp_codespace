/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:16:35 by seoson            #+#    #+#             */
/*   Updated: 2024/01/19 14:27:39 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename Func>
void	iter(T a[], size_t length, Func& func)
{
	for (size_t i = 0; i < length; i++)
	{
		func(a[i]);
	}
}
template<typename T, typename Func>
void	iter(const T a[], size_t length, Func& func)
{
	for (size_t i = 0; i < length; i++)
	{
		func(a[i]);
	}
}


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:16:35 by seoson            #+#    #+#             */
/*   Updated: 2024/01/17 22:38:52 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename Func>
void	iter(T a[], int length, Func func)
{
	for (int i = 0; i < length; i++)
	{
		func(a[i]);
	}
}


#endif

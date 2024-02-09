/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:02:01 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/23 15:17:26 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

template <typename T>
bool easyfind(T& a, int i)
{
	typename T::iterator iter = std::find(a.begin(), a.end(),i);
	if (iter == a.end())
		return (false);
	return (true);
};

template <typename T>
bool easyfind(std::queue<T>& a, int i)
{
	std::queue<T> iter = a;
	while (!iter.empty())
	{
		if (iter.front() == i)
			return (true);
		iter.pop();
	}
	return (false);
};

template <typename T>
bool easyfind(std::stack<T>& a, int i)
{
	std::stack<T> iter = a;
	while (!iter.empty())
	{
		if (iter.top() == i)
			return (true);
		iter.pop();
	}
	return (false);
};

template <typename T>
bool easyfind(std::priority_queue<T>& a, int i)
{
	std::priority_queue<T> iter = a;
	while (!iter.empty())
	{
		if (iter.top() == i)
			return (true);
		iter.pop();
	}
	return (false);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:49:22 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/20 22:26:37 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec;
	std::deque<int> q;
	std::list<int> a;
	std::stack<int> s;
	vec.push_back(3);
	q.push_back(2);
	s.push(3);
	std::cout << easyfind(vec,1) << std::endl;
	std::cout << easyfind(q,2) << std::endl;
	std::cout << easyfind(a,2) << std::endl;
	std::cout << easyfind(s,2) << std::endl;
	std::cout << s.top() << std::endl;
	return (0);
}
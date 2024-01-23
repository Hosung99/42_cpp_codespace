/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:52:04 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/22 00:38:59 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{

	Span sp(10002);
	try{
		// for (int i = 0; i < 10001; i++)
		// 	sp.addNumber(i);
		sp.addNumbers(1,10001);
		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
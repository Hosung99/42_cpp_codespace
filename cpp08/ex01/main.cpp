/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:52:04 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/21 15:27:46 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(2147483647);
	// try{
	// 	sp.addNumber(1);
	// 	sp.addNumber(1);
	// }catch(std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	try{
		for (int i = 0; i < 10001; i++)
			sp.addNumber(i);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:03:31 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/11 17:26:25 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *a;
	Bureaucrat *b;
	Bureaucrat *c;
	try
	{
		a = new Bureaucrat("seoson1", 150);
		std::cout << *a;
		a->decrement();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b = new Bureaucrat("seoson2", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		c = new Bureaucrat("seoson3", 1);
		c->increment();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete a;
	delete b;
	delete c;
	return (0);
}

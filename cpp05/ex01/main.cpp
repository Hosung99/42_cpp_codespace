/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:03:31 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/11 17:49:16 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *a = NULL;
	Bureaucrat *b = NULL;
	Bureaucrat *c = NULL;
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
	if (b)
		delete b;
	delete c;
	return (0);
}

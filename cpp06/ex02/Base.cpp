/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:29:35 by seoson            #+#    #+#             */
/*   Updated: 2024/01/17 14:35:16 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"

Base::~Base()
{
	std::cout << "Base Destructor Called" << std::endl;
}

Base*	generate(void)
{
	srand(time(NULL));
	int rand_int = rand() % 100;
	if (rand_int < 33)
		return (new A());
	else if (rand_int >= 33 && rand_int < 67)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "class is A!" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "class is B!" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "class is C!" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "class is A!!" << std::endl;
	}
	catch (std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "class is B!!" << std::endl;
	}
	catch (std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "class is C!!" << std::endl;
	}
	catch (std::exception& e){}
}

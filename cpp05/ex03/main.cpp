/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:03:31 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/13 15:09:04 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	AForm *rrf = NULL;
	Bureaucrat *b = NULL;
	try
	{
		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		b = new Bureaucrat("seoson", 1);
		b->signForm(*rrf);
		b->executeForm(*rrf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	if (rrf)
		delete rrf;
	if (b)
		delete b;
	return (0);
}
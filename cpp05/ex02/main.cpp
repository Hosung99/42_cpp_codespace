/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:03:31 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/12 20:11:19 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	*a = NULL;
	AForm		*form_shru = NULL;
	AForm		*form_robot = NULL;
	AForm		*form_president = NULL;
	try
	{
		a = new Bureaucrat("seoson1", 1);
		form_shru = new ShrubberryCreationForm("home");
		std::cout << *form_shru << std::endl;
		form_shru->beSigned(*a);
		a->executeForm(*form_shru);
		std::cout << *form_shru << std::endl;
		form_robot = new RobotomyRequestForm("robot1");
		std::cout << *form_robot << std::endl;
		form_robot->beSigned(*a);
		a->executeForm(*form_robot);
		form_president = new PresidentialPardonForm("Yun Seok yul");
		std::cout << *form_president << std::endl;
		form_president->beSigned(*a);
		a->executeForm(*form_president);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete a;
	if (form_shru)
		delete form_shru;
	if (form_robot)
		delete form_robot;
	if (form_president)
		delete form_president;
	return (0);
}

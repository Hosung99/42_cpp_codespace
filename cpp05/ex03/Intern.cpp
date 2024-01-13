/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:02:26 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/13 12:51:44 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Default Destructor Called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern&	Intern::operator=(const Intern &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

AForm*	Intern::makeShrubberryForm(std::string target)
{
	return (new ShrubberryCreationForm(target));
}

AForm*	Intern::makeRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::TypeMatchingException::what() const throw()
{
	return ("FORM NAME DOESN'T EXIST!");
}

AForm* Intern::makeForm(std::string type, std::string name)
{
	AForm* (Intern::*form[3])(std::string) = { &Intern::makeShrubberryForm, &Intern::makeRobotomyForm, &Intern::makePresidentialForm };
	const std::string types[3] = {"shrubberry creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (types[i] == type)
		{
			std::cout << "Intern creates " << types[i] << "form" << std::endl;
			return (this->*form[i])(name);
		}
	}
	throw (TypeMatchingException());
}
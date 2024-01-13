/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:37:54 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/13 10:54:11 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)
{
	this->setName(name);
	this->setGradeExcute(false);
	this->setGradeSign(25);
	this->setGradeExcute(5);
	std::cout << "PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	*this = other;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return (*this);
	this->setName(other.getName());
	this->setIsSigned(other.getIsSigned());
	this->setGradeSign(other.getGradeExcute());
	this->setGradeExcute(other.getGradeExcute());
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& other) const
{
	if (this->getIsSigned() == false)
		throw (AForm::FormIsntSignedException());
	if (this->getGradeExcute() < other.getGrade())
		throw (AForm::GradeTooLowException());
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
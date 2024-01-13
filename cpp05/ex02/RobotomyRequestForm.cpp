/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:16:51 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/13 16:50:28 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name)
{
	this->setName(name);
	this->setIsSigned(false);
	this->setGradeSign(72);
	this->setGradeExcute(45);
	std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return (*this);
	this->setName(other.getName());
	this->setIsSigned(other.getIsSigned());
	this->setGradeSign(other.getGradeSign());
	this->setGradeExcute(other.getGradeExcute());
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat& other) const
{
	if (this->getIsSigned() == false)
		throw (AForm::FormIsntSignedException());
	if (this->getGradeExcute() < other.getGrade())
		throw (AForm::GradeTooLowException());
	std::cout << "Drrrrrrrrrrrrrrrrrrr...." << std::endl;
	srand(time(NULL));
	int rand_int = rand() % 100;
	if (rand_int < 50)
		std::cout << "Robotmized Success!" << std::endl;
	else
		std::cout << "Robotmized Failed.." << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:10:10 by seoson            #+#    #+#             */
/*   Updated: 2024/01/13 14:49:53 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("null"), isSigned(false), grade_sign(150), grade_excute(150)
{
	std::cout << "Default Form Constructor Called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Default Form Destructor Called" << std::endl;
}

AForm::AForm(const std::string name, const int grade_first, const int grade_second) : name(name), isSigned(false), grade_sign(grade_first), grade_excute(grade_second)
{
	if (grade_first < 1 || grade_second < 1)
		throw(GradeTooHighException());
	if (grade_first > 150 || grade_second > 150)
		throw(GradeTooLowException());
	std::cout << "Form " << name << " Constructor Called" << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), grade_sign(other.grade_sign), grade_excute(other.grade_excute)
{
	std::cout << "Form " << other.name << " Copy Constructor Called" << std::endl;
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this == &other)
		return (*this);

	this->setName(other.getName());
	this->isSigned = other.isSigned;
	this->setGradeSign(other.getGradeSign());
	this->setGradeExcute(other.getGradeExcute());
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is Too High!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is Too Low!");
}

const char*
AForm::FormIsntSignedException::what() const throw()
{
	return ("Warning :: Form Isn't Signed!");
}

void	AForm::beSigned(const Bureaucrat& other)
{
	if (this->grade_sign < other.getGrade())
		throw (GradeTooLowException());
	this->isSigned = true;
}

const std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getIsSigned() const
{
	return (this->isSigned);
}

int	AForm::getGradeSign() const
{
	return (this->grade_sign);
}

int	AForm::getGradeExcute() const
{
	return (this->grade_excute);
}

void	AForm::setIsSigned(bool target)
{
	this->isSigned = target;
}

void	AForm::setGradeSign(int target)
{
	int &const_grade_sign = const_cast<int &>(this->grade_sign);
	const_grade_sign = target;
}

void	AForm::setGradeExcute(int target)
{
	int &const_grade_excute = const_cast<int &>(this->grade_excute);
	const_grade_excute = target;
}

void	AForm::setName(std::string name)
{
	std::string &constName = const_cast<std::string &>(this->name);
	constName = name;
}

std::ostream&	operator<<(std::ostream& out, const AForm& form)
{
	out << form.getName() << " is ";
	if (form.getIsSigned())
		out << "signed ";
	else
		out << "unsigned ";
	out << "and grade to sign is " << form.getGradeSign() << ", grade to excute is " << form.getGradeExcute();
	return (out);
}

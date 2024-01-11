/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:10:10 by seoson            #+#    #+#             */
/*   Updated: 2024/01/11 20:36:00 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("null"), isSigned(false), grade_sign(150), grade_excute(150)
{
	std::cout << "Default Form Constructor Called" << std::endl;
}

Form::~Form()
{
	std::cout << "Default Form Destructor Called" << std::endl;
}

Form::Form(const std::string name, const int grade_first, const int grade_second) : name(name), isSigned(false), grade_sign(grade_first), grade_excute(grade_second)
{
	if (grade_first < 1 || grade_second < 1)
		throw(GradeTooHighException());
	if (grade_first > 150 || grade_second > 150)
		throw(GradeTooLowException());
	std::cout << "Form " << name << " Constructor Called" << std::endl;
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), grade_sign(other.grade_sign), grade_excute(other.grade_excute)
{
	std::cout << "Form " << other.name << " Copy Constructor Called" << std::endl;
}

Form&	Form::operator=(const Form& other)
{
	if (this == &other)
		return (*this);
	std::string &constName = const_cast<std::string &>(this->name);
	constName = other.name;

	this->isSigned = other.isSigned;

	int &const_grade_sign = const_cast<int &>(this->grade_sign);
	const_grade_sign = this->grade_sign;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Grade is Lower!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Grade is Higher!");
}

void	Form::beSigned(const Bureaucrat& other)
{
	if (this->grade_sign < other.getGrade())
		throw (GradeTooLowException());
	this->isSigned = true;

}

const std::string	Form::getName() const
{
	return (this->name);
}

const bool	Form::getIsSigned() const
{
	return (this->isSigned);
}

const int	Form::getGradeSign() const
{
	return (this->grade_sign);
}

const int	Form::getGradeExcute() const
{
	return (this->grade_excute);
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << " is ";
	if (form.getIsSigned())
		out << "signed";
	else
		out << "unsigned";
	out << "grade to sign is " << form.getGradeSign() << " grade to excute is" << form.getGradeExcute();
	return (out);
}

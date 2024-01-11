/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:32:42 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/11 20:47:28 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Unknown"), grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Default Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	std::cout << "Bureaucrat " << name << " Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	std::string &constName = const_cast<std::string &>(this->name);
	constName = other.getName();
	this->grade = other.getGrade();
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is Too High Exception Fault");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is Too Low Exception Fault");
}

void	Bureaucrat::increment()
{
	if (this->grade <= 1)
		throw (GradeTooHighException());
	this->grade--;
}

void	Bureaucrat::decrement()
{
	if (this->grade >= 150)
		throw (GradeTooLowException());
	this->grade++;
}

void	Bureaucrat::signForm(const Form& form)
{
	if (form.getIsSigned())
		std::cout << this->getName() << " signed Form" << std::endl;
	else
		std::cout << this->getName() << "couldn't sign form because grade " << this->getGrade() << " is Too low. " << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:35:27 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/12 16:08:04 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberryCreationForm.hpp"

ShrubberryCreationForm::ShrubberryCreationForm(std::string name)
{
	this->setName(name);
	this->setIsSigned(false);
	this->setGradeSign(145);
	this->setGradeExcute(137);
	std::cout << "ShrubberryCreationForm Constructor Called" << std::endl;
}

ShrubberryCreationForm::~ShrubberryCreationForm()
{
	std::cout << "ShrubberryCreationForm Destructor Called" << std::endl;
}

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm& other) : AForm(other)
{
	*this = other;
}

ShrubberryCreationForm&	ShrubberryCreationForm::operator=(const ShrubberryCreationForm& other)
{
	if (this == &other)
		return (*this);
	this->setName(other.getName());
	this->setIsSigned(other.getIsSigned());
	this->setGradeSign(other.getGradeSign());
	this->setGradeExcute(other.getGradeExcute());
	return (*this);
}

void	ShrubberryCreationForm::execute(const Bureaucrat& other) const
{
	if (this->getIsSigned() == false)
		throw (AForm::FormIsntSignedException());
	if (this->getGradeExcute() < other.getGrade())
		throw (AForm::GradeTooLowException());
	std::fstream	file;
	std::string		file_name;
	file_name = this->getName() + "_shrubbery";
	file.open(file_name.c_str(),std::ios::out);
	if (!file.is_open())
	{
		std::cout << "Error: open file failed" << std::endl;
		return ;
	}
	file << ascii_tree;
	file.close();
}
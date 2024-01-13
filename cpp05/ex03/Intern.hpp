/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:13:54 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/13 12:06:59 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &);
		Intern	&operator=(const Intern &);
		AForm*	makeForm(std::string name, std::string target);
		AForm*	makeShrubberryForm(std::string name);
		AForm*	makeRobotomyForm(std::string name);
		AForm*	makePresidentialForm(std::string name);
		class	TypeMatchingException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
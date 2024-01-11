/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:09:25 by seoson            #+#    #+#             */
/*   Updated: 2024/01/11 20:46:50 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			grade_sign;
		const int			grade_excute;
	public:
		Form();
		~Form();
		Form(const std::string, const int, const int);
		Form(const Form&);
		Form&				operator=(const Form&);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		void				beSigned(const Bureaucrat&);
		const std::string	getName() const;
		const bool			getIsSigned() const;
		const int			getGradeSign() const;
		const int			getGradeExcute () const;

};

std::ostream& operator<<(std::ostream &out, const Form&);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:09:25 by seoson            #+#    #+#             */
/*   Updated: 2024/01/12 10:57:45 by Sungho           ###   ########.fr       */
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
		bool				getIsSigned() const;
		int					getGradeSign() const;
		int					getGradeExcute () const;

};

std::ostream& operator<<(std::ostream &out, const Form&);

#endif

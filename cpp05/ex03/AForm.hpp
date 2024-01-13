/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:09:25 by seoson            #+#    #+#             */
/*   Updated: 2024/01/13 10:45:55 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			grade_sign;
		const int			grade_excute;
	public:
		AForm();
		virtual ~AForm();
		AForm(const std::string, const int, const int);
		AForm(const AForm&);
		AForm&				operator=(const AForm&);
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
		class FormIsntSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		void				beSigned(const Bureaucrat&);
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeSign() const;
		int					getGradeExcute () const;
		void				setIsSigned(bool);
		void				setGradeSign(int);
		void				setGradeExcute(int);
		void				setName(std::string);
		virtual void		execute(Bureaucrat const &) const = 0;
};

std::ostream& operator<<(std::ostream &out, const AForm&);

#endif

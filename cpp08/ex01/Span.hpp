/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:36:11 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/22 00:33:15 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private:
		std::vector<int>	vec;
		unsigned int		vec_size;
		Span();
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span& other);
		Span&				operator=(const Span& other);
		void				addNumber(int);
		void				addNumbers(int, int);
		int					shortestSpan();
		int					longestSpan();
		size_t				size() const;
		int					get_i(unsigned int) const;
		class sizeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class spanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class indexException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class wrongRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Span& other);

#endif
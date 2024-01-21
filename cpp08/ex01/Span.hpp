/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:36:11 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/21 15:22:05 by Sungho           ###   ########.fr       */
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
		unsigned int		size;
		Span();
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span& other);
		Span&	operator=(const Span& other);
		void	addNumber(int);
		int		shortestSpan();
		int		longestSpan();
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
		class dupException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
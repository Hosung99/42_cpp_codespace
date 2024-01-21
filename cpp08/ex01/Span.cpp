/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:50:50 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/21 15:27:10 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->size = N;
}

Span::~Span()
{
	std::cout << "Default Span Destructor Called" << std::endl;
}

Span::Span(const Span& other)
{
	*this = other;
}

Span&	Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
	this->vec = other.vec;
	this->size = other.size;
	return (*this);
}

void	Span::addNumber(int N)
{
	if (this->vec.size() == this->size)
		throw(sizeException());
	std::vector<int>::iterator iter = std::find(this->vec.begin(), this->vec.end(), N);
	if (iter != this->vec.end())
		throw (dupException());
	this->vec.push_back(N);
}

int	Span::shortestSpan()
{
	if (this->vec.size() <= 1)
		throw(spanException());
	std::vector<int> temp_vec = this->vec;
	std::sort(temp_vec.begin(), temp_vec.end());
	int min_diff = 2147483647;
	for(size_t i = 0; i < temp_vec.size() - 1; i++)
	{
		int diff = temp_vec[i + 1] - temp_vec[i];
		if (diff < min_diff)
			min_diff = diff;
	}
	return (min_diff);
}

int	Span::longestSpan()
{
	if (this->vec.size() <= 1)
		throw(spanException());
	return (*std::max_element(this->vec.begin(), this->vec.end()) - *std::min_element(this->vec.begin(), this->vec.end()));
}

const char* Span::sizeException::what() const throw()
{
	return ("Vector is Full!");
}

const char* Span::spanException::what() const throw()
{
	return ("Vector size is under one!");
}

const char* Span::dupException::what() const throw()
{
	return ("Vector has Same Vaule!");
}
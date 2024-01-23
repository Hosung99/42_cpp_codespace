/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:50:50 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/22 00:38:00 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	std::cout << "Default Span Constructor Called" << std::endl;
	this->vec.reserve(N);
	this->vec_size = N;
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
	this->vec_size = other.vec_size;
	return (*this);
}

void	Span::addNumber(int N)
{
	if (this->vec.size() == this->vec_size)
		throw (sizeException());
	this->vec.push_back(N);
}

void	Span::addNumbers(int begin, int end)
{
	if (begin > end)
		throw (wrongRangeException());
	for(int index = begin; index <= end; index++)
	{
		if (this->vec.size() == this->vec_size)
			throw (sizeException());
		this->vec.push_back(index);
	}
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

size_t Span::size() const
{
	return (this->vec.size());
}

int	Span::get_i(unsigned int index) const
{
	if (this->vec_size <= index)
		throw (indexException());
	return (vec[index]);
}

const char* Span::sizeException::what() const throw()
{
	return ("Vector is Full!");
}

const char* Span::spanException::what() const throw()
{
	return ("Vector size is under one!");
}

const char* Span::indexException::what() const throw()
{
	return ("Vector index is Wrong!");
}

const char* Span::wrongRangeException::what() const throw()
{
	return ("Range is Wrong!");
}

std::ostream& operator<<(std::ostream &out, const Span& other)
{
	for(unsigned int i = 0; i < other.size(); i++)
	{
		out << "index[" << i << "]: " << other.get_i(i) << std::endl;
	}
	return (out);
}
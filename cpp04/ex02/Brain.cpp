/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:24:26 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/03 17:15:43 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Default Destructor Called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this == &other)
		return (*this);
	for (int ideas_idx = 0; ideas_idx < 100; ideas_idx++)
		this->ideas[ideas_idx] = other.ideas[ideas_idx];
	return (*this);
}

void	Brain::setIdeas(int index, std::string text)
{
	if (index < 0 || index > 99)
		return ;
	this->ideas[index] = text;
}

std::string	Brain::getIdeas(int index)
{
	if (index < 0 || index > 99)
		return ("null");
	return (this->ideas[index]);
}
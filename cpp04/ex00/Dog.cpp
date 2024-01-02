/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:05:57 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/02 11:46:16 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Default Destructor Called" << std::endl;
}

Dog::Dog(const Dog& dog)
{
	*this = dog;
}

Dog&	Dog::operator=(const Dog& dog)
{
	if (this == &dog)
		return (*this);
	this->type = dog.getType();
	return (*this);
}

std::string	Dog::getType() const
{
	return (this->type);
}

void	Dog::makeSound()
{
	std::cout << "Bark! Bark!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Bark! Bark!" << std::endl;
}

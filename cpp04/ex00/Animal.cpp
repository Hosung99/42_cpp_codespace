/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:09:37 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/08 09:54:54 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("null")
{
	std::cout << "Default Animal Constructor Called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default Animal Destructor Called" << std::endl;
}

Animal::Animal(const Animal& animal)
{
	*this = animal;
}

Animal&	Animal::operator=(const Animal& animal)
{
	if (this == &animal)
		return (*this);
	this->type = animal.getType();
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound()
{
	std::cout << "Animal Default Sound" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal Default Sound" << std::endl;
}

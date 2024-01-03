/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:05:57 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/03 17:13:43 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Default Destructor Called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	this->type = dog.getType();
	this->brain = new Brain(*dog.brain);
}

Dog&	Dog::operator=(const Dog& dog)
{
	if (this == &dog)
		return (*this);
	delete this->brain;
	this->type = dog.getType();
	this->brain = new Brain(*dog.brain);
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

void	Dog::setIdeas(int index, std::string text)
{
	this->brain->setIdeas(index, text);
}

std::string	Dog::getIdeas(int index)
{
	return (this->brain->getIdeas(index));
}
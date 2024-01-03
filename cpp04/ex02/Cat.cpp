/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:22:20 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/03 17:48:07 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Default Destructor Called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	this->type = cat.getType();
	this->brain = new Brain(*cat.brain);
}

Cat&	Cat::operator=(const Cat& cat)
{
	if (this == &cat)
		return (*this);
	delete this->brain;
	this->type = cat.getType();
	this->brain = new Brain(*cat.brain);
	return (*this);
}

std::string	Cat::getType() const
{
	return (this->type);
}

void	Cat::makeSound()
{
	std::cout << "Meow~ Meow~" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow~ Meow~" << std::endl;
}

void	Cat::setIdeas(int index, std::string text)
{
	this->brain->setIdeas(index, text);
}

std::string	Cat::getIdeas(int index)
{
	return (this->brain->getIdeas(index));
}
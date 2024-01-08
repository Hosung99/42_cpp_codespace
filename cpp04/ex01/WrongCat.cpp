/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:29:30 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/02 21:41:49 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Default Destructor Called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	*this = other;
}

void	WrongCat::makeSound()
{
	std::cout << "MEOM~ MEWOM~" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "MEOM~ MEOM~" << std::endl;
}

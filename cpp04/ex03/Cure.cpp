/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:52:00 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/04 19:09:52 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
	std::cout << "Default Cure Constructor Called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Default Cure Destructor Called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	*this = other;
}

Cure&	Cure::operator=(const Cure& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

AMateria*	Cure::clone() const
{
	std::cout << "Clone Cure Materia" << std::endl;
	Cure *temp = new Cure();
	return (temp);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

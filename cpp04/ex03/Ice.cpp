/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:29:32 by seoson            #+#    #+#             */
/*   Updated: 2024/01/04 22:22:37 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
	std::cout << "Default Ice Constructor Called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Default Ice Destructor Called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	*this = other;
}

Ice&	Ice::operator=(const Ice& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

AMateria*	Ice::clone() const
{
	std::cout << "Clone Ice Materia" << std::endl;
	Ice	*ice = new Ice();
	return (ice);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
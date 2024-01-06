/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:51:37 by seoson            #+#    #+#             */
/*   Updated: 2024/01/04 22:23:01 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Default Constructor Called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Default Destructor Called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << "AMateria type Constructor Called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Can't do with AMateria at " << target.getName() << std::endl;
}

std::string const&	AMateria::getType() const
{
	return (this->type);
}

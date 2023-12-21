/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 05:26:47 by codespace         #+#    #+#             */
/*   Updated: 2023/12/20 06:06:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Make a New Weapon" << std::endl;
}

Weapon::~Weapon(){}

Weapon::Weapon(std::string type)
{
	std::cout << "Make a New Weapon" << std::endl;
	this->type = type;
}

const std::string& Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

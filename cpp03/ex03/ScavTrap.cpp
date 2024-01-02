/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:52:14 by seoson            #+#    #+#             */
/*   Updated: 2024/01/02 06:43:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "ScavTrap Default Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "ScavTrap named " << this->name << " Constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Default Destructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scav) : ClapTrap(scav)
{
	*this = scav;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& scav)
{
	if (this == &scav)
		return (*this);
	this->name = scav.name;
	this->Hit_points = scav.Hit_points;
	this->Energy_points = scav.Energy_points;
	this->Attack_damage = scav.Attack_damage;
	return (*this);
}

void	ScavTrap::attack()
{
	if (this->Energy_points == 0)
	{
		std::cout << "Energy Point is 0. Can't to nothing" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks something " << this->Attack_damage << " points of damage!" << std::endl;
	this->Energy_points--;
}

void	ScavTrap::guardGate()
{
	if (this->Energy_points == 0)
	{
		std::cout << "Energy Point is 0. Can't to nothing" << std::endl;
		return ;
	}
	std::cout << "ScavTrap is now in Gatekeeper Mode." << std::endl;
}

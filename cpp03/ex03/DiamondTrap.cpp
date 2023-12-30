/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:18:00 by seoson            #+#    #+#             */
/*   Updated: 2023/12/30 22:40:22 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->name = "Diamond Default name";
	std::cout << "DiamondTrap Default Constructor" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Default Destructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	ClapTrap(name + "_clap_name");
	this->name = name;
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_damage = FragTrap::Attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamond)
{
	*this = diamond;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& diamond)
{
	if (this == &diamond)
		return (*this);
	this->name = diamond.name;
	this->FragTrap::Hit_points = diamond.FragTrap::Hit_points;
	this->ScavTrap::Energy_points = diamond.ScavTrap::Energy_points;
	this->FragTrap::Attack_damage = diamond.FragTrap::Attack_damage;
	return (*this);
}

void	DiamondTrap::attack()
{
	this->ScavTrap::attack();
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << this->name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::name << std::endl;
}

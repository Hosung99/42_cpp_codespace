/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:18:00 by seoson            #+#    #+#             */
/*   Updated: 2024/01/02 06:44:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), name("Default")
{
	std::cout << "DiamondTrap Default Constructor" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Default Destructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	this->Hit_points = FragTrap::Frag_Hit_points;
	this->Energy_points = ScavTrap::Scav_Energy_points;
	this->Attack_damage = FragTrap::Frag_Attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamond) : ClapTrap(diamond), FragTrap(diamond), ScavTrap(diamond)
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

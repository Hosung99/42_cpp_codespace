/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:36:18 by seoson            #+#    #+#             */
/*   Updated: 2024/01/02 06:37:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("null"),Hit_points(10),Energy_points(10),Attack_damage(0)
{
	std::cout << "ClapTrap Default Constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name):Hit_points(10), Energy_points(10), Attack_damage(0)
{
	this->name = name;
	std::cout << "ClapTrap named " << this->name << " Constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Default Destructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	if (this == &claptrap)
		return (*this);
	this->name = claptrap.name;
	this->Hit_points = claptrap.Hit_points;
	this->Energy_points = claptrap.Energy_points;
	this->Attack_damage = claptrap.Attack_damage;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	*this = claptrap;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->Energy_points == 0)
	{
		std::cout << "Energy Point is 0. Can't to nothing" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
	this->Energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_points == 0)
	{
		std::cout << "already dead." << std::endl;
		return ;
	}
	if (this->Hit_points < amount)
		Hit_points = 0;
	else
		this->Hit_points -= amount;
	std::cout << "ClapTrap Taken " << amount <<  "Damage. rest HP : " << this->Hit_points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Energy_points == 0)
	{
		std::cout << "Energy Point is 0. Can't to nothing" << std::endl;
		return ;
	}
	if (this->Hit_points + amount > 4294967294)
	{
		std::cout << "Energy Overflow caused." << std::endl;
		return ;
	}
	this->Hit_points += amount;
	std::cout << "ClapTrap is been repaired rest HP : " << this->Hit_points << std::endl;
	this->Energy_points--;
}

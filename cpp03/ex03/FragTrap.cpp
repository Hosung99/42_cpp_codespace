/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:33 by seoson            #+#    #+#             */
/*   Updated: 2023/12/30 22:18:35 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap Default Constructor" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Default Destructor" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap named " << this->name << " Constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& frag)
{
	*this = frag;
}

FragTrap &FragTrap::operator=(const FragTrap& frag)
{
	if (this == &frag)
		return (*this);
	this->name = frag.name;
	this->Hit_points = frag.Hit_points;
	this->Energy_points = frag.Energy_points;
	this->Attack_damage = frag.Attack_damage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->Energy_points == 0)
	{
		std::cout << "Energy Point is 0. Can't to nothing" << std::endl;
		return ;
	}
	std::cout << "FragTrap HighFive!" << std::endl;
}

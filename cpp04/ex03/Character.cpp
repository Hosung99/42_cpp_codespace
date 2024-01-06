/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:16:26 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/06 15:32:22 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
	std::cout << "Character Default Constructor Called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] != NULL)
			delete (this->materia[i]);
	}
	std::cout << "Character" << this->name << " Destructor Called" << std::endl;
}

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
	std::cout << "Character " << name << " Constructor Called" << std::endl;
}

Character::Character(const Character& other)
{
	for (int i = 0; i < 4; i++)
		if (other.materia[i])
			this->materia[i] = other.materia[i]->clone();
	this->name = other.getName();
}

Character&	Character::operator=(const Character& other)
{
	if (this == &other)
		return (*this);
	for(int i = 0 ; i < 4; i++)
	{
		if (this->materia[i])
			delete this->materia[i];
		if (other.materia[i])
			this->materia[i] = other.materia[i]->clone();
	}
	this->name = other.getName();
	return (*this);
}

std::string const&	Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Materia is NULL." << std::endl;
		return ;
	}
	int i = 0;
	while (this->materia[i] != NULL && i < 4)
		i++;
	if (i == 4)
	{
		std::cout << "Inventory is Fulled." << std::endl;
		return ;
	}
	this->materia[i] = m;
	std::cout << "Materia " << i << " is equied with " << m->getType() << std::endl;
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Wrong Index!" << std::endl;
		return ;
	}
	if (this->materia[idx] == NULL)
	{
		std::cout << "Materia is already unequied!" << std::endl;
		return ;
	}
	this->materia[idx] = NULL;
	std::cout << "Materia index " << idx << " is unequied!" << std::endl;
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Wrong Index!" << std::endl;
		return ;
	}
	if (this->materia[idx] == NULL)
	{
		std::cout << "Material Idx " << idx << " doesn't exist!" << std::endl;
		return ;
	}
	this->materia[idx]->use(target);
}

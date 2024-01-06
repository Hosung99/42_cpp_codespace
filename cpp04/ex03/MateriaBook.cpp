/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaBook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:46:31 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/06 15:40:42 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaBook.hpp"

MateriaBook::MateriaBook()
{
	for (int i = 0; i < this->MAX_MAGIC_NUMBER; i++)
		this->materia[i] = NULL;
	std::cout << "MateriaBook Default Constructor Called." << std::endl;
}

MateriaBook::~MateriaBook()
{
	for (int i = 0; i < this->MAX_MAGIC_NUMBER; i++)
	{
		if (this->materia[i] != NULL)
			delete this->materia[i];
	}
	std::cout << "MateriaBook Default Destructor Called." << std::endl;
}

MateriaBook::MateriaBook(const MateriaBook& other)
{
	for (int i = 0; i < this->MAX_MAGIC_NUMBER; i++)
	{
		if (other.materia[i] != NULL)
			this->materia[i] = other.materia[i]->clone();
	}
}

MateriaBook&	MateriaBook::operator=(const MateriaBook& other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < this->MAX_MAGIC_NUMBER; i++)
	{
		if (this->materia[i] != NULL)
			delete this->materia[i];
		if (other.materia[i] != NULL)
			this->materia[i] = other.materia[i]->clone();
	}
	return (*this);
}

void	MateriaBook::set_materia(AMateria* materia)
{
	int i = 0;
	while (this->materia[i] != NULL && i < this->MAX_MAGIC_NUMBER)
		i++;
	if (i == this->MAX_MAGIC_NUMBER)
	{
		std::cout << "Magic is Fulled!" << std::endl;
		return ;
	}
	this->materia[i] = materia;
	return ;
}

AMateria*	MateriaBook::get_materia(int idx)
{
	if (idx < 0 || idx > 999)
	{
		std::cout << "Wrong Index!" << std::endl;
		return NULL;
	}
	if (this->materia[idx] == NULL)
	{
		std::cout << "Index " << idx << " is NULL!" << std::endl;
		return NULL;
	}
	return (this->materia[idx]);
}
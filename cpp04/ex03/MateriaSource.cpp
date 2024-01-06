/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:02:53 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/06 15:30:03 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
	std::cout << "MateriaSource Default Constructor Called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if(this->materia[i])
			delete this->materia[i];
	std::cout << "MateriaSource Default Destructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.materia[i] != NULL)
			this->materia[i] = other.materia[i]->clone();
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] != NULL)
			delete this->materia[i];
		if (other.materia[i] != NULL)
			this->materia[i] = other.materia[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == NULL)
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
	this->materia[i] = materia;
	std::cout << "Materia " << materia->getType() << " is learned" << std::endl;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (type == this->materia[i]->getType())
			return (this->materia[i]->clone());
	std::cout << "The Type of " << type << "Doesn't Exist!" << std::endl;
	return (NULL);
}

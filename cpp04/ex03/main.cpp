/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:21:37 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/06 15:40:56 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaBook.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

// void foo(void)
// {
// 	system("leaks a.out");
// }

int main(void)
{
	// atexit(foo);
	MateriaBook	*book = new MateriaBook();
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	// src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	book->set_materia(src->createMateria("ice"));
	book->set_materia(src->createMateria("cure"));
	me->equip(book->get_materia(0));
	me->equip(book->get_materia(1));
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->unequip(1);
	delete bob;
	delete me;
	delete src;
	delete book;
	return 0;
}
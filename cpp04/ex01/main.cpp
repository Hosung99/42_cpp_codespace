/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:46:09 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/03 17:43:01 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal*	animal[6];

	for (int animal_idx = 0; animal_idx < 3; animal_idx++)
		animal[animal_idx] = new Dog();
	for (int animal_idx = 3; animal_idx < 6; animal_idx++)
		animal[animal_idx] = new Cat();
	for (int animal_idx = 0; animal_idx < 6; animal_idx++)
		delete animal[animal_idx];

	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog(*dog1);

	dog1->setIdeas(0,"hi1");
	dog2->setIdeas(0,"hi2");
	std::cout << "dog1 : " << dog1->getIdeas(0) << std::endl;
	std::cout << "dog2 : " << dog2->getIdeas(0) << std::endl;

	dog1->setIdeas(0, "hi3");
	dog2->setIdeas(0, "hi4");
	std::cout << "dog1 : " << dog1->getIdeas(0) << std::endl;
	std::cout << "dog2 : " << dog2->getIdeas(0) << std::endl;
	delete dog1;
	delete dog2;
	return (0);
}

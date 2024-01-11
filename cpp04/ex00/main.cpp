/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:46:09 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/10 16:05:58 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wanimal = new WrongAnimal();
	const WrongCat* wcat = new WrongCat();
	const WrongAnimal* wrong_example = new WrongCat();
	const Animal* right_example = new Dog();
	wanimal->makeSound();
	wcat->makeSound();
	wrong_example->makeSound();
	right_example->makeSound();

	delete meta;
	delete i;
	delete j;
	delete wanimal;
	delete wcat;
	delete wrong_example;
	delete right_example;
	return (0);
}

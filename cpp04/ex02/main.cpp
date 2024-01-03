/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:46:09 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/03 17:31:30 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// Animal*	animal = new Animal();

	Dog*	dog = new Dog();
	Cat*	cat = new Cat();

	dog->makeSound();
	cat->makeSound();
	return (0);
}

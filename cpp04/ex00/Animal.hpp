/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:09:49 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/02 12:30:03 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		~Animal();
		Animal(const Animal& animal);
		Animal&		operator=(const Animal& animal);
		std::string	getType() const;
		virtual void		makeSound() const;
		virtual void		makeSound();
};

#endif

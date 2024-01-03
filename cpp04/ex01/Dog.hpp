/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:29:21 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/03 17:12:08 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog& dog);
		Dog&		operator=(const Dog& dog);
		std::string	getType() const;
		void		makeSound();
		void		makeSound() const;
		void		setIdeas(int index, std::string text);
		std::string	getIdeas(int index);
};

#endif

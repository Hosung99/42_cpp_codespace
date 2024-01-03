/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:27:07 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/03 17:48:04 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& cat);
		Cat&			operator=(const Cat& cat);
		std::string		getType() const;
		virtual void	makeSound();
		virtual void	makeSound() const;
		void			setIdeas(int index, std::string text);
		std::string		getIdeas(int index);
};

#endif

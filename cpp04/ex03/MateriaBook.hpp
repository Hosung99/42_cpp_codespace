/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaBook.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:37:25 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/06 15:23:44 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIABOOK_HPP
# define MATERIABOOK_HPP

#include "AMateria.hpp"

class MateriaBook
{
	private:
		static const int	MAX_MAGIC_NUMBER = 1000;
		AMateria*			materia[MAX_MAGIC_NUMBER];
	public:
		MateriaBook();
		~MateriaBook();
		MateriaBook(const MateriaBook& other);
		MateriaBook&	operator=(const MateriaBook& other);
		void			set_materia(AMateria*);
		AMateria*		get_materia(int idx);
};

#endif
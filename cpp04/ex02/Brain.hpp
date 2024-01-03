/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:19:16 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/03 17:12:30 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		virtual ~Brain();
		Brain(const Brain& other);
		Brain&		operator=(const Brain& other);
		void		setIdeas(int index, std::string text);
		std::string	getIdeas(int index);
};

#endif
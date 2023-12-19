/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 05:39:55 by codespace         #+#    #+#             */
/*   Updated: 2023/12/19 11:05:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cstdio>

class PhoneBook
{
	private:
		int		contact_cnt;
		int		contact_index;
		Contact contacts[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add();
		void	search();
};

#endif

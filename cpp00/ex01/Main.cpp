/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 04:50:21 by codespace         #+#    #+#             */
/*   Updated: 2023/12/19 11:13:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdio>

static void	set_cin(void);

int main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "Enter command : ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			set_cin();
		if (command.compare("EXIT") == 0)
			break;
		else if (command.compare("ADD") == 0)
			phonebook.add();
		else if (command.compare("SEARCH") == 0)
			phonebook.search();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}

void set_cin(void)
{
	clearerr(stdin);
	std::cin.clear();
}

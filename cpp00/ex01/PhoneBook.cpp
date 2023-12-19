/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 04:32:04 by codespace         #+#    #+#             */
/*   Updated: 2023/12/16 12:58:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	set_cin(void)
{
	clearerr(stdin);
	std::cin.clear();
	std::cout << std::endl;
	return ;
}

PhoneBook::PhoneBook()
{
	this->contact_cnt = 0;
	this->contact_index = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook remove" << std::endl;
}

void	PhoneBook::add()
{
	std::string str_arr[5] = {
		"Enter first name : ",
		"Enter last name : ",
		"Enter nickname : ",
		"Enter phone number : ",
		"Enter darkest secret : "
	};
	std::string str_contact[5];
	for (int str_index = 0; str_index < 5; str_index++)
	{
		do{
			std::cout << str_arr[str_index];
			std::getline(std::cin, str_contact[str_index]);
			if (std::cin.eof())
				set_cin();
		} while (str_contact[str_index] == "" || std::cin.eof());
	}
	Contact contact(str_contact, this->contact_index);
    this->contacts[this->contact_index] = contact;
    this->contact_index = (this->contact_index + 1) % 8;
	this->contact_cnt++;
}

static int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	PhoneBook::search()
{
	std::string	search_index;
	int			index;

	std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10) \
		<< "first name" << "|" << std::setw(10) << "last name" << "|" << \
		std::setw(10) << "nickname" << "|" << std::endl;

	for (int contact_index = 0; contact_index < min(this->contact_cnt, 8); contact_index++)
		this->contacts[contact_index].print();

	if (this->contact_cnt < 1)
		return ;
	do{
		std::cout << "Enter Search index : ";
		std::getline(std::cin, search_index);
		if (std::cin.eof())
			set_cin();
	} while (search_index == "" || std::cin.eof());

	if (search_index.length() != 1 || !isdigit(search_index[0]))
		std::cout << "Invalid index" << std::endl;
	else
	{
		index = search_index[0] - '0';
		if (index < 0 || index > 7)
			std::cout << "Invalid index" << std::endl;
		else
		{
			if (index < this->contact_cnt)
				this->contacts[index].print();
			else
				std::cout << "Not found" << std::endl;
		}
	}
}

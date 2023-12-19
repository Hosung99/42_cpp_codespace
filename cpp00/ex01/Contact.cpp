/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 05:42:01 by codespace         #+#    #+#             */
/*   Updated: 2023/12/19 11:10:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->index = 0;
}

Contact::Contact(std::string str[], int index)
{
	for (int str_index = 0; str_index < 5; str_index++)
		this->contact_info[str_index] = str[str_index];
	this->index = index;
}

Contact::~Contact(){ }

void	Contact::print()
{
	std::cout << "|" << std::setw(10) << this->index;
	for (int str_index = 0; str_index < 3; str_index++)
	{
		std::cout << "|";
		if (this->contact_info[str_index].length() > 10)
			std::cout << this->contact_info[str_index].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->contact_info[str_index];
	}
	std::cout << "|" << std::endl;
}

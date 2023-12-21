/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:52:17 by codespace         #+#    #+#             */
/*   Updated: 2023/12/21 09:26:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::string level;

	while (1)
	{
		std::cout << "Enter level: ";
		std::getline(std::cin, level);
		if (level == "exit")
			break ;
		harl.complain(level);
	}
	return (0);
}

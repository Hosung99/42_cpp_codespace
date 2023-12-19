/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 01:59:07 by codespace         #+#    #+#             */
/*   Updated: 2023/12/18 13:36:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static std::string toUpper(char **argv);

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::cout << toUpper(argv) << std::endl;
	return (0);
}

std::string toUpper(char **argv)
{
	std::string str;
	for (int argv_index = 1; argv[argv_index]; argv_index++)
		str += argv[argv_index];
	for (long unsigned int str_index = 0; str_index < str.length(); str_index++)
	{
		if (str[str_index] >= 'a' && str[str_index] <= 'z')
			str[str_index] = str[str_index] - 32;
		else
			str[str_index] = str[str_index];
	}
	return (str);
}

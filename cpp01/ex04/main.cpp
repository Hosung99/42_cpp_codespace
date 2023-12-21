/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 07:49:04 by codespace         #+#    #+#             */
/*   Updated: 2023/12/20 12:33:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{
	std::fstream	file;
	std::string		char_to_string[3];

	if (argc != 4)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
	for (int argc_index = 0; argc_index < argc - 1; argc_index++)
		char_to_string[argc_index] = argv[argc_index + 1];
	if (!char_to_string[1].compare(""))
	{
		std::cout << "Error: Empty string" << std::endl;
		return (1);
	}
	file.open(char_to_string[0].c_str(), std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Error: Invalid file" << std::endl;
		return (1);
	}
	std::string	str;
	std::string fileName;
	str = replace(file, char_to_string);
	fileName = argv[1] + std::string(".replace");
	file.close();
	file.open(fileName.c_str(), std::ios::out);
	if (!file.is_open())
	{
		std::cout << "Error: open file failed" << std::endl;
		return (1);
	}
	file << str;
	file.close();
	return (0);
}

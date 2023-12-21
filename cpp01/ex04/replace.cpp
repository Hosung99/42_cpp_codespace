/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:32:45 by codespace         #+#    #+#             */
/*   Updated: 2023/12/20 12:33:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string	replace(std::fstream &file, std::string *char_to_string)
{
	size_t pos;
	std::string	str;
	std::string	str_tmp;
	while (1)
	{
		char *tmp = new char[char_to_string[1].length() + 1];
		file.read(tmp, char_to_string[1].length());
		str_tmp = std::string(tmp);
		pos = str_tmp.find(char_to_string[1]);
		if (pos != std::string::npos)
		{
			str_tmp.erase(pos, char_to_string[1].length());
			str_tmp.insert(pos, char_to_string[2]);
			pos += char_to_string[1].length();
		}
		str += str_tmp;
		delete [] tmp;
		if (file.eof())
			break ;
	}
	return (str);
}

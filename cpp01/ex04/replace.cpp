/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:32:45 by codespace         #+#    #+#             */
/*   Updated: 2024/01/02 21:03:09 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string	replace(std::fstream &file, std::string *char_to_string)
{
	size_t pos;
	std::string	str,line;

	while (std::getline(file, line))
		str += line;
	while (1)
	{
		pos = str.find(char_to_string[1]);
		if (pos != std::string::npos)
		{
			str.erase(pos, char_to_string[1].length());
			str.insert(pos, char_to_string[2]);
			pos += char_to_string[1].length();
		}
		else
			break ;
	}
	return (str);
}

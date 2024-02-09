/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:59:05 by Sungho            #+#    #+#             */
/*   Updated: 2024/02/10 01:28:28 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *str)
{
	std::fstream file;
	std::string str, line;
	file.open(str, std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Error: open file failed" << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		// size_t pos = line.find()
	}
}

BitcoinExchange::~BitcoinExchange()
{
}
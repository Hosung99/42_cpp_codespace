/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:53:56 by Sungho            #+#    #+#             */
/*   Updated: 2024/02/10 01:21:50 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
	private:
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange&	operator=(const BitcoinExchange&);
		std::map<std::string, int>	m;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(char *);
};

#endif
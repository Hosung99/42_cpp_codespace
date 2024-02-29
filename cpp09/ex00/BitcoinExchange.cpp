/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:59:05 by Sungho            #+#    #+#             */
/*   Updated: 2024/02/11 20:25:34 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int check_day(int year, int month, int day)
{
	if (month == 2)
	{
		if (day > 29)
			throw(std::logic_error("Error: leap year's day is over 0 under 30"));
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			return (29);
		else
			return (28);
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return 31;
}

float BitcoinExchange::check_value_validate(std::string str)
{
	char *char_temp = NULL;
	float ret;
	ret = std::strtod(str.c_str(), &char_temp);
	if (errno == ERANGE)
		throw(std::logic_error("Error: casting range error."));
	if (ret < 0)
		throw(std::logic_error("Error: value can only positive."));
	if (*char_temp && std::strcmp(char_temp, "f"))
		throw(std::logic_error("Error: value can only float."));
	return ret;
}

void BitcoinExchange::check_date_validate(std::string str)
{
	std::istringstream iss(str);
	std::string buffer;
	double year, month, day, iss_idx = 0;

	while (std::getline(iss, buffer, '-'))
	{
		char *char_temp = NULL;
		if (iss_idx == 0)
			year = std::strtod(buffer.c_str(), &char_temp);
		else if (iss_idx == 1)
			month = std::strtod(buffer.c_str(), &char_temp);
		else if (iss_idx == 2)
			day = std::strtod(buffer.c_str(), &char_temp);
		if (*char_temp)
			throw(std::logic_error("Error: Date has not digit."));
		iss_idx++;
	}
	if (iss_idx != 3)
	{
		throw(std::logic_error("Error: date format is Year-Month-Day"));
	}
	if (year <= 0 || year >= 10000)
	{
		throw(std::logic_error("Error: Year is over 0 under 10000."));
	}
	if (month < 1 || month > 12)
	{
		throw(std::logic_error("Error: Month is over 0 under 13."));
	}
	if (day < 1 || day > check_day(year, month, day))
	{
		throw(std::logic_error("Error: Day is over 0 under 32."));
	}
}
BitcoinExchange::BitcoinExchange()
{
	std::fstream file;
	std::string str, line;
	float value;

	file.open("./data.csv", std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Error: open Data.csv" << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		if (line != "date,exchange_rate")
		{
			size_t pos = line.find(',');
			str = line.substr(0, pos);
			try
			{
				if (pos == std::string::npos)
				{
					throw(std::logic_error("Error: data argument is not validate"));
				}
				check_date_validate(str);
				value = check_value_validate(line.substr(pos + 1, line.length()));
				m.insert(std::make_pair(str, value));
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::calc(char *file_name)
{
	std::fstream file;
	std::string str, line;
	std::map<std::string, float>::iterator iter;
	float value;

	file.open(file_name, std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Error: open " << file_name << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		if (line != "date | value")
		{
			size_t pos = line.find('|');
			str = line.substr(0, pos - 1);
			try
			{
				if (pos == std::string::npos)
				{
					std::cout << "Error: bad input => ";
					throw(std::logic_error(str));
				}
				check_date_validate(str);
				value = check_value_validate(line.substr(pos + 2, line.length()));
				if (value < 0 || value > 1000)
					throw(std::logic_error("Error: value is between 0 and 1000"));
				iter = m.find(str);
				if (iter == m.end())
				{
					iter = m.lower_bound(str);
					if (iter == m.end() || iter == m.begin())
					{
						throw(std::logic_error("Error: date is least 2009-01-02"));
					}
					iter--;
				}
				std::cout << iter->first << " => " << value << " = " << iter->second * value << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
}
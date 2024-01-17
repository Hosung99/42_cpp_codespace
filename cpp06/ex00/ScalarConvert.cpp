/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:30:01 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/17 15:45:59 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

static void	print_char(double convert_d, std::string str)
{
	if (str == "nan" || std::numeric_limits<char>::max() < convert_d || std::numeric_limits<char>::min() > convert_d)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char c = static_cast<char>(convert_d);
	if (!std::isprint(c))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << c << "'" << std::endl;
}

static void	print_int(double convert_d, std::string str)
{
	if (str == "nan" || std::numeric_limits<int>::max() < convert_d || std::numeric_limits<int>::min() > convert_d)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	int i = static_cast<int>(convert_d);
	std::cout << "int: " << i << std::endl;
}

static void	print_float(double convert_d, std::string str)
{
	if (str == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	if (std::numeric_limits<float>::max() < convert_d || -std::numeric_limits<float>::max() > convert_d)
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	float f = static_cast<float>(convert_d);
	size_t dot_pos = str.find('.');
	size_t str_len = str.length();
	if (str[str_len - 1] == 'f' && (!dot_pos || str[str_len - 2] != '.'))
		str_len--;
	if (dot_pos == std::string::npos)
		str_len = 1;
	std::cout << "float: " << std::fixed << std::setprecision(str_len - dot_pos - 1) << f << "f" << std::endl;
}

static void	print_double(double convert_d, std::string str)
{
	if (str == "nan")
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (errno == ERANGE)
	{
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	std::cout << "double: " << convert_d << std::endl;
}

void ScalarConvert::convert(std::string str)
{
	double	convert_d;
	char	*char_temp;

	if (str.length() == 1 && str[0] != '0')
		convert_d = static_cast<double>(str[0]);
	else
	{
		convert_d = std::strtod(str.c_str(), &char_temp);
		if (str.find('0') && !convert_d)
		{
			std::cout << "Can't Convert!" << std::endl;
			return ;
		}
	}
	print_char(convert_d, str);
	print_int(convert_d, str);
	print_float(convert_d, str);
	print_double(convert_d, str);
}

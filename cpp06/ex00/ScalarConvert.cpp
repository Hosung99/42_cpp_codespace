/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:30:01 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/14 18:27:27 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

static	void	print_char(double convert_d)
{
	if (std::isnan(convert_d))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (std::isprint(convert_d))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: " << convert_d << std::endl;
}

void ScalarConvert::convert(std::string str)
{
	// bool	double_overflow_flag = false;
	double	convert_d;
	char	*char_temp;

	convert_d = std::strtod(str.c_str(), &char_temp);
	std::cout << convert_d << std::endl;
	// if (errno == ERANGE)
		// double_overflow_flag = true;
	print_char(convert_d);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:39:05 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/14 18:24:38 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "ERROR: Argument Count" << std::endl;
		return (1);
	}
	std::string str = argv[1];
	ScalarConvert::convert(str);
	return (0);
}
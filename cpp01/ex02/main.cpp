/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:51:34 by codespace         #+#    #+#             */
/*   Updated: 2023/12/23 21:17:43 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string_variable;
	std::string *string_PTR;
	std::string &string_REF = string_variable;

	string_variable = "HI THIS IS BRAIN";
	string_PTR = &string_variable;
	std::cout << "Memory of : string_variable: " << &string_variable << std::endl;
	std::cout << "Memory of : string_PTR: " << string_PTR << std::endl;
	std::cout << "Memory of : string_REF: " << &string_REF << std::endl;

	std::cout << "Memory of : string_variable: " << string_variable << std::endl;
	std::cout << "Memory of : string_PTR: " << *string_PTR << std::endl;
	std::cout << "Memory of : string_REF: " << string_REF << std::endl;

	// string_REF = "HI THIS IS BRAIN REF";
	// std::cout << "Memory of : string_variable: " << string_variable << std::endl;
	// std::cout << "Memory of : string_PTR: " << *string_PTR << std::endl;
	// std::cout << "Memory of : string_REF: " << string_REF << std::endl;
	return (0);
}

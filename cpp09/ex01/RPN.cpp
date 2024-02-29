/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:18:24 by Sungho            #+#    #+#             */
/*   Updated: 2024/02/12 14:49:01 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(char *str)
{
	std::istringstream iss(str);
	std::string buffer;

	while (std::getline(iss, buffer, ' '))
	{
		if (buffer == "(" || buffer == ")")
		{
			throw(std::logic_error("Error"));
		}
		if (!(buffer >= "0" && buffer <= "9"))
		{
			if (buffer != "+" && buffer != "-" && buffer != "/" && buffer != "*")
			{
				throw(std::logic_error("Error"));
			}
		}
		if (buffer.length() != 1)
		{
			throw(std::logic_error("Error"));
		}
		st.push(buffer);
		calculate();
	}
	std::cout << calc_st.top() << "\n";
}

void RPN::calculate()
{
	std::string string_temp = st.top();
	double first, second;
	st.pop();
	if (string_temp == "+" || string_temp == "-" || string_temp == "*" || string_temp == "/")
	{
		if (calc_st.size() < 2)
			throw(std::logic_error("Error"));
		first = calc_st.top();
		calc_st.pop();
		second = calc_st.top();
		calc_st.pop();
		calc_st.push(operation(first, second, string_temp));
	}
	else
	{
		char *temp = NULL;
		double double_temp = strtod(string_temp.c_str(), &temp);
		calc_st.push(double_temp);
	}
}

double RPN::operation(double first, double second, std::string c)
{
	if (c == "+")
		return (first + second);
	else if (c == "-")
		return (second - first);
	else if (c == "*")
		return (first * second);
	else if (c == "/")
	{
		if (first == 0.0)
			throw(std::logic_error("Error"));
		return (second / first);
	}
	else
		return (0);
}

RPN::~RPN()
{
}
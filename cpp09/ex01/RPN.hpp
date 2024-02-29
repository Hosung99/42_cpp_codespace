/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:11:01 by Sungho            #+#    #+#             */
/*   Updated: 2024/02/12 14:40:56 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
private:
	std::stack<std::string>	st;
	std::stack<double>	calc_st;
	RPN(const RPN &);
	RPN &operator=(const RPN &);
	RPN();
	double operation(double, double, std::string);

public:
	RPN(char *);
	~RPN();
	void calculate();
};

#endif
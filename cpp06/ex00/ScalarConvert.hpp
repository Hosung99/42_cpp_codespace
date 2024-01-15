/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:52:51 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/14 18:02:23 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#define OVERFLOW 1

#include <iostream>
#include <cerrno>

class ScalarConvert
{
	private:
		ScalarConvert();
		~ScalarConvert();
		ScalarConvert(const ScalarConvert&);
		ScalarConvert&	operator=(const ScalarConvert&);
	public:
		static	void	convert(std::string);
};

#endif
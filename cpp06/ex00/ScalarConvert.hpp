/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:52:51 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/17 14:17:33 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#define OVERFLOW 1

#include <iostream>
#include <cerrno>
#include <cmath>
#include <iomanip>
#include <limits>
#include <stdlib.h>

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

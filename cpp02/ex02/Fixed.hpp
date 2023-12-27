/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 06:32:11 by codespace         #+#    #+#             */
/*   Updated: 2023/12/27 11:37:04 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					RawBits;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed	&operator=(const Fixed &fixed);
		bool	operator>(const Fixed &fixed);
		bool	operator<(const Fixed &fixed);
		bool	operator>=(const Fixed &fixed);
		bool	operator<=(const Fixed &fixed);
		bool	operator==(const Fixed &fixed);
		bool	operator!=(const Fixed &fixed);
		float	operator+(const Fixed &fixed);
		float	operator-(const Fixed &fixed);
		float	operator*(const Fixed &fixed);
		float	operator/(const Fixed &fixed);
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		static Fixed	&max(Fixed& a, Fixed& b);
		static const Fixed	&max(const Fixed& a, const Fixed& b);
		static Fixed	&min(Fixed& a, Fixed& b);
		static const Fixed	&min(const Fixed& a, const Fixed& b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

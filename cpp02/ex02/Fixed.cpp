/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 06:38:30 by codespace         #+#    #+#             */
/*   Updated: 2023/12/27 11:37:00 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->RawBits = fixed.RawBits;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->RawBits = value << 8;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->RawBits = roundf(value * 256);
}

float Fixed::toFloat(void) const
{
	return ((float)this->RawBits / 256);
}

int Fixed::toInt(void) const
{
	return (this->RawBits >> 8);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->RawBits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->RawBits = raw;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->RawBits = fixed.RawBits;
	return *this;
}

bool Fixed::operator<(const Fixed &fixed)
{
	if (this->RawBits < fixed.RawBits)
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed &fixed)
{
	if (this->RawBits > fixed.RawBits)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &fixed)
{
	if (this->RawBits <= fixed.RawBits)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &fixed)
{
	if (this->RawBits >= fixed.RawBits)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &fixed)
{
	if (this->RawBits == fixed.RawBits)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &fixed)
{
	if (this->RawBits != fixed.RawBits)
		return (true);
	return (false);
}

float Fixed::operator+(const Fixed &fixed)
{
	return (this->toFloat()+ fixed.toFloat());
}

float Fixed::operator-(const Fixed &fixed)
{
	return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(const Fixed &fixed)
{
	return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(const Fixed &fixed)
{
	if (fixed.toFloat() == 0)
	{
		std::cout << "Can't divide Zero" << std::endl;
		exit(1);
	}
	return (this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++()
{
	this->RawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->RawBits++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->RawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->RawBits--;
	return (temp);
}

Fixed	&Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed	&Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

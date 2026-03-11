/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:32:26 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/01/01 00:40:19 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// ex00
Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fixedValue = 0;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedValue = raw;
}

// ex01
Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = i << this->_fractionBits;
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(f * (1 << this->_fractionBits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedValue / (1 << this->_fractionBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedValue >> this->_fractionBits);
}

// If use Fixed class without any function at std::cout for directelly
// then, It need to overloading.
std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}

// ex02
bool Fixed::operator>(const Fixed& other) const
{
	return (this->_fixedValue > other._fixedValue);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_fixedValue < other._fixedValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_fixedValue >= other._fixedValue);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_fixedValue <= other._fixedValue);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_fixedValue == other._fixedValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_fixedValue != other._fixedValue);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->_fixedValue++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++this->_fixedValue;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->_fixedValue--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--this->_fixedValue;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a < b ? b : a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a < b ? b : a);
}

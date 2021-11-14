/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:15:55 by agautier          #+#    #+#             */
/*   Updated: 2021/11/14 21:11:53 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

/*
**	Initilization of non members attributes.
*/
int const Fixed::_fractional_bits = 8;

/*
**	Default constructor.
*/
Fixed::Fixed(void) : _raw_bits(0) {}

/*
**	Copy constructor.
*/
Fixed::Fixed(Fixed const& fixed) { *this = fixed; }

/*
**	Integer constructor.
*/
Fixed::Fixed(int const nb) : _raw_bits(nb << _fractional_bits) {}

/*
**	Floating point constructor.
*/
Fixed::Fixed(float const nb) :
	_raw_bits(roundf(nb * (1 << _fractional_bits))) {}

/*
**	Destructor.
*/
Fixed::~Fixed(void) {}

/*
**	Fixed point to float.
*/
float Fixed::toFloat(void) const {
	return ((float)_raw_bits / (float)(1 << _fractional_bits));
}

/*
**	Fixed point to int.
*/
int Fixed::toInt(void) const { return (_raw_bits >> _fractional_bits); }

/*
**	Returns the raw raw_bits of the fixed point.
*/
int Fixed::getRawBits(void) const { return (_raw_bits); }

/*
**	Sets the value of the fixed point.
*/
void Fixed::setRawBits(int const value) { _raw_bits = value; }

/*
**	Returns the smaller of a and b.
*/
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b ? a : b); }

/*
**	Returns the smaller of a and b.
*/
Fixed const& Fixed::min(Fixed const& a, Fixed const& b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

/*
**	Returns the greater of a and b.
*/
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b ? a : b); }

/*
**	Returns the greater of a and b.
*/
Fixed const& Fixed::max(Fixed const& a, Fixed const& b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

/*
**	Assignation operator overload.
*/
Fixed& Fixed::operator=(Fixed const& fixed) {
	if (this == &fixed)
		return (*this);
	_raw_bits = fixed._raw_bits;
	return (*this);
}

/*
**	Greater operator overload.
*/
bool Fixed::operator>(Fixed const& fixed) {
	return (_raw_bits > fixed._raw_bits);
}

/*
**	Less operator overload.
*/
bool Fixed::operator<(Fixed const& fixed) {
	return (_raw_bits < fixed._raw_bits);
}

/*
**	Less or equal operator overload.
*/
bool Fixed::operator<=(Fixed const& fixed) {
	return (_raw_bits <= fixed._raw_bits);
}

/*
**	Greater or equal operator overload.
*/
bool Fixed::operator>=(Fixed const& fixed) {
	return (_raw_bits <= fixed._raw_bits);
}

/*
**	Equal operator overload.
*/
bool Fixed::operator==(Fixed const& fixed) {
	return (_raw_bits == fixed._raw_bits);
}

/*
**	Not equal operator overload.
*/
bool Fixed::operator!=(Fixed const& fixed) {
	return (_raw_bits == fixed._raw_bits);
}

/*
**	Addition operator overload.
*/
Fixed const Fixed::operator+(Fixed const& fixed) {
	return (this->toFloat() + fixed.toFloat());
}

/*
**	Subtraction operator overload.
*/
Fixed const Fixed::operator-(Fixed const& fixed) {
	return (this->toFloat() - fixed.toFloat());
}

/*
**	Multiplication operator overload.
*/
Fixed const Fixed::operator*(Fixed const& fixed) {
	return (this->toFloat() * fixed.toFloat());
}

/*
**	Division operator overload.
*/
Fixed const Fixed::operator/(Fixed const& fixed) {
	return (this->toFloat() / fixed.toFloat());
}

/*
**	Prefix increment operator overload.
*/
Fixed& Fixed::operator++(void) {
	_raw_bits++;
	return (*this);
}

/*
**	Postfix increment operator overload.
*/
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);

	this->operator++();
	return (tmp);
}

/*
**	Prefix decrement operator overload.
*/
Fixed& Fixed::operator--(void) {
	_raw_bits--;
	return (*this);
}

/*
**	Postfix decrement operator overload.
*/
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);

	this->operator--();
	return (tmp);
}

/*
**	Output operator overload.
*/
std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
	os << fixed.toFloat();
	return (os);
}


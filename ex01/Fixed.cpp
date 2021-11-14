/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:15:55 by agautier          #+#    #+#             */
/*   Updated: 2021/11/14 15:28:15 by agautier         ###   ########.fr       */
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
Fixed::Fixed(void) : _raw_bits(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*
**	Copy constructor.
*/
Fixed::Fixed(Fixed const& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

/*
**	Integer constructor.
*/
Fixed::Fixed(int const nb) : _raw_bits(nb << _fractional_bits) {
	std::cout << "Int constructor called" << std::endl;
}

/*
**	Floating point constructor.
*/
Fixed::Fixed(float const nb) : _raw_bits(roundf(nb * (1 << _fractional_bits))) {
	std::cout << "Float constructor called" << std::endl;
}

/*
**	Destructor.
*/
Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

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
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_raw_bits);
}

/*
**	Sets the value of the fixed point.
*/
void Fixed::setRawBits(int const value) {
	std::cout << "setRawBits member function called" << std::endl;
	_raw_bits = value;
}

/*
**	Assignation operator overload.
*/
Fixed& Fixed::operator=(Fixed const& fixed) {
	std::cout << "Assignation operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	_raw_bits = fixed._raw_bits;
	return (*this);
}

/*
**	Output operator overload.
*/
std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
	os << fixed.toFloat();
	return (os);
}


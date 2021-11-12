/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:15:55 by agautier          #+#    #+#             */
/*   Updated: 2021/11/12 22:34:24 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/*
**	Initilization of non members attributes.
*/
const int Fixed::_fractional_bits = 8;

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
**	Destructor.
*/
Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

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
	_raw_bits = fixed.getRawBits();
	return (*this);
}


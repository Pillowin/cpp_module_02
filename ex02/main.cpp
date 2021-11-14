/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:36:51 by agautier          #+#    #+#             */
/*   Updated: 2021/11/14 21:05:20 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void test_comparaison(Fixed& a, Fixed const& b) {
	std::cout << std::endl << "- test_comparaison" << std::endl << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;

	std::cout << "a is ";
	if (!(a > b))
		std::cout << "not ";
	std::cout << "greater than b" << std::endl;

	std::cout << "a is ";
	if (!(a < b))
		std::cout << "not ";
	std::cout << "less than b" << std::endl;

	std::cout << "a is ";
	if (!(a >= b))
		std::cout << "not ";
	std::cout << "greater or equal than b" << std::endl;

	std::cout << "a is ";
	if (!(a >= b))
		std::cout << "not ";
	std::cout << "greater or equal than b" << std::endl;

	std::cout << "a is ";
	if (!(a == b))
		std::cout << "not ";
	std::cout << "equal to b" << std::endl;

	std::cout << "a is ";
	if (!(a != b))
		std::cout << "not ";
	std::cout << "not equal to b" << std::endl;
}

void test_arithmetic_op(Fixed& a, Fixed const& b) {
	std::cout << std::endl << "- test_arithmetic_op" << std::endl << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
}

void test_increment_op(Fixed& a) {
	std::cout << std::endl << "- test_increment_op" << std::endl << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a is " << a << std::endl;
}

void test_min_max() {
	std::cout << std::endl << "- test_min_max" << std::endl << std::endl;

	Fixed a(1.0f);
	Fixed b(2.0f);

	std::cout << "Max of 1.0 and 2.0 is " << Fixed::max(a, b) << std::endl;
	std::cout << "Max of 1.0 and 2.0 is " << Fixed::max(1.0f, 2.0f)
			  << std::endl;

	std::cout << "Min of 1.0 and 2.0 is " << Fixed::min(a, b) << std::endl;
	std::cout << "Min of 1.0 and 2.0 is " << Fixed::min(1.0f, 2.0f)
			  << std::endl;
}

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	Fixed fixed(4.5f);
	test_comparaison(fixed, 2.0f);
	test_arithmetic_op(fixed, 2.0f);
	test_increment_op(fixed);
	test_min_max();

	return (0);
}

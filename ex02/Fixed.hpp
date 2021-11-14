/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:12:25 by agautier          #+#    #+#             */
/*   Updated: 2021/11/14 21:02:52 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const& fixed);
		Fixed(int const nb);
		Fixed(float const nb);

		virtual ~Fixed(void);

		float toFloat(void) const;
		int toInt(void) const;

		int getRawBits(void) const;
		void setRawBits(int const value);

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed const& min(Fixed const& a, Fixed const& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed const& max(Fixed const& a, Fixed const& b);

		Fixed& operator=(Fixed const& fixed);

		bool operator>(Fixed const& fixed);
		bool operator<(Fixed const& fixed);
		bool operator<=(Fixed const& fixed);
		bool operator>=(Fixed const& fixed);
		bool operator==(Fixed const& fixed);
		bool operator!=(Fixed const& fixed);

		Fixed const operator+(Fixed const& fixed);
		Fixed const operator-(Fixed const& fixed);
		Fixed const operator*(Fixed const& fixed);
		Fixed const operator/(Fixed const& fixed);

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

	private:
		int _raw_bits;
		static int const _fractional_bits;
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:12:25 by agautier          #+#    #+#             */
/*   Updated: 2021/11/14 15:24:52 by agautier         ###   ########.fr       */
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

		Fixed& operator=(Fixed const& fixed);

	private:
		int _raw_bits;
		static int const _fractional_bits;
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif

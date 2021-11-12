/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:12:25 by agautier          #+#    #+#             */
/*   Updated: 2021/11/12 17:10:50 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const& fixed);

		virtual ~Fixed(void);

		Fixed& operator=(Fixed const& fixed);

		int getRawBits(void) const;
		void setRawBits(int const value);

	private:
		int _raw_bits;
		static const int _fractional_bits;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:23:37 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/26 10:24:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	_value;
		int static const _bits = 8;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float bits);
		Fixed(const Fixed &another);
		~Fixed(void);
		float	toFloat(void) const;
		int		toInt(void) const;
		int getRawBits(void) const;
		void setRawBits (int const raw);
		Fixed &operator=(const Fixed &another);
};

std::ostream &operator<<(std::ostream &os, const Fixed &another);

#endif
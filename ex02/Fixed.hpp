/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:23:37 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/26 12:09:13 by sasalama         ###   ########.fr       */
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
		bool operator>(const Fixed &another) const;
		bool operator<(const Fixed &another) const;
		bool operator>=(const Fixed &another) const;
		bool operator<=(const Fixed &another) const;
		bool operator==(const Fixed &another) const;
		bool operator!=(const Fixed &another) const;
		Fixed operator+(const Fixed &another) const;
		Fixed operator-(const Fixed &another) const;
		Fixed operator*(const Fixed &another) const;
		Fixed operator/(const Fixed &another) const;
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int value);
		Fixed operator--(int value);
		static const Fixed &max(const Fixed &another, const Fixed &another2);
		static const Fixed &min(const Fixed &another, const Fixed &another2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &another);


#endif
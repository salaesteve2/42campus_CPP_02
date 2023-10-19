/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:23:30 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/26 09:12:06 by sasalama         ###   ########.fr       */
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
		Fixed(const Fixed &another);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits (int const raw);
		Fixed &operator=(const Fixed &another);
};

#endif

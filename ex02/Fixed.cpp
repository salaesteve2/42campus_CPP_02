/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:23:35 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/26 12:10:44 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _bits;
}

Fixed::Fixed(const float bits)
{
	float	x;

	std::cout << "Float constructor called" << std::endl;
	x = (bits * (1 << _bits));
	_value = x;
}

Fixed::Fixed(const Fixed &another)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(another);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "Assignation operator called" << std::endl;
	_value = raw;
	this->getRawBits();
}

Fixed	&Fixed::operator=(const Fixed &another)
{
	if (this != &another)
		this->setRawBits(another._value);
	return (*this);
}

float	Fixed::toFloat(void) const
{
	float	x;

	x = (float)_value / (float)(1 << _bits);
	return (x);
}

int	Fixed::toInt(void) const
{
	int	x;

	x = _value >> _bits;
	return (x);
}

std::ostream &operator<<(std::ostream &os, const Fixed &another)
{
	os << another.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed &another) const
{
	bool x;

	x = 0;
	if (this->toFloat() > another.toFloat())
		x = 1;
	return (x);
}

bool Fixed::operator<(const Fixed &another) const
{
	bool x;

	x = 0;
	if (this->toFloat() < another.toFloat())
		x = 1;
	return (x);
}

bool Fixed::operator>=(const Fixed &another) const
{
	bool x;

	x = 0;
	if (this->toFloat() > another.toFloat() || this->toFloat() == another.toFloat())
		x = 1;
	return (x);
}

bool Fixed::operator<=(const Fixed &another) const
{
	bool x;

	x = 0;
	if (this->toFloat() < another.toFloat() || this->toFloat() == another.toFloat())
		x = 1;
	return (x);
}

bool Fixed::operator==(const Fixed &another) const
{
	bool x;

	x = 0;
	if (this->toFloat() == another.toFloat())
		x = 1;
	return (x);
}

bool Fixed::operator!=(const Fixed &another) const
{
	bool x;

	x = 0;
	if (this->toFloat() != another.toFloat())
		x = 1;
	return (x);
}

Fixed Fixed::operator+(const Fixed &another) const
{
	Fixed res(this->toFloat() + another.toFloat());
	return (res);
}

Fixed Fixed::operator-(const Fixed &another) const
{
	Fixed res(this->toFloat() - another.toFloat());
	return (res);
}

Fixed Fixed::operator*(const Fixed &another) const
{
	Fixed res(this->toFloat() * another.toFloat());
	return (res);
}

Fixed Fixed::operator/(const Fixed &another) const
{
	Fixed res(this->toFloat() / another.toFloat());
	return (res);
}

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int value)
{
	Fixed aux;

	aux = *this;
	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (aux);
}

Fixed Fixed::operator--(int value)
{
	Fixed aux;

	aux = *this;
	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (aux);
}

const Fixed &Fixed::max(const Fixed &another, const Fixed &another2)
{
	if (another > another2)
		return (another);
	return (another2);
}

const Fixed &Fixed::min(const Fixed &another, const Fixed &another2)
{
	if (another < another2)
		return (another);
	return (another2);
}

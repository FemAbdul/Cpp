/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:34:29 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/16 11:34:29 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include<cmath>

Fixed::Fixed():value(0)
{	
	// std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& fix)
{
	*this = fix;
	// std::cout<<"Copy Constructor called"<<std::endl;
}

Fixed::~Fixed()
{
	// std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits()const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& fix)
{
	// std::cout<<"Copy Assignment operator called"<<std::endl;
	this->setRawBits(fix.getRawBits());
	return (*this);
}

//Constructor that takes an int and convert to fixed point
Fixed::Fixed(const int val):value(val * (1 << Fixed::bits))
{
	// std::cout<<"Int constructor called"<<std::endl;
}

//Member Function To convert a fixed point to an int
int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits);
}

//Contructor that takes a float and converts to fixed point
Fixed::Fixed(const float val):value(roundf(val * (1 << Fixed::bits)))
{
	// std::cout<<"Float constructor called"<<std::endl;
}

//To convert a fixed point to a float
float Fixed::toFloat(void) const
{
	return ((float)(this->value) / (float)(1 << Fixed::bits));
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}

//Comparison operator overloading
bool Fixed::operator>(const Fixed& fix)
{
	return (this->value > fix.getRawBits());
}

bool Fixed::operator<(const Fixed& fix)
{
	return (this->value < fix.getRawBits());
}

bool Fixed::operator>=(const Fixed& fix)
{
	return (this->value >= fix.getRawBits());
}

bool Fixed::operator<=(const Fixed& fix)
{
	return (this->value <= fix.getRawBits());
}

bool Fixed::operator==(const Fixed& fix)
{
	return (this->value == fix.getRawBits());
}

bool Fixed::operator!=(const Fixed& fix)
{
	return (this->value != fix.getRawBits());
}

//Arithmetic operator overloading
Fixed Fixed::operator+(const Fixed& fix) const
{
	return (Fixed(this->toFloat() + fix.toFloat()));
}

Fixed Fixed::operator-(const Fixed& fix) const
{
	return (Fixed(this->toFloat() - fix.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fix) const
{
	return (Fixed(this->toFloat() * fix.toFloat()));
}

Fixed Fixed::operator/(const Fixed& fix) const
{
	return (Fixed(this->toFloat() / fix.toFloat()));
}

//Increment/Decrement operator overloading
Fixed& Fixed::operator++(void)//pre increment
{
	this->value += 1;
	return (*this);
}

Fixed Fixed::operator++(int)//post incrment
{
	Fixed temp = *this;
	this->value += 1;
	return (temp);
}

Fixed& Fixed::operator--(void)//pre increment
{
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)//post incrment
{
	Fixed temp = *this;
	this->value -= 1;
	return (temp);
}

//Static member function
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
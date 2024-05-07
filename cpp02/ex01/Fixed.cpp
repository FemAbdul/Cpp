/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:25:03 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/13 21:25:03 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include<cmath>

Fixed::Fixed():value(0)
{	
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& fix)
{
	std::cout<<"Copy Constructor called"<<std::endl;
	*this = fix;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
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
	std::cout<<"Copy Assignment operator called"<<std::endl;
	this->setRawBits(fix.getRawBits());
	return (*this);
}
//Constructor that takes an int and convert to fixed point
Fixed::Fixed(const int val):value(val * (1 << Fixed::bits))
{
	std::cout<<"Int constructor called"<<std::endl;
}

int Fixed::toInt(void) const //To convert a fixed point to an int
{
	return (this->value >> Fixed::bits);
}

//Contructor that takes a float and converts to fixed point
Fixed::Fixed(const float val):value(roundf(val * (1 << Fixed::bits)))
{
	std::cout<<"Float constructor called"<<std::endl;
}

//To convert a fixed point to a float
float Fixed::toFloat(void) const //To convert a fixed point to an int
{
	return ((float)(this->value) / (float)(1 << Fixed::bits));
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:56:42 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/12 23:56:42 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constuctor
Fixed::Fixed():value(0)
{	
	std::cout<<"Default constructor called"<<std::endl;
}
//Copy constructor
Fixed::Fixed(const Fixed& fix)
{
	std::cout<<"Copy Constructor called"<<std::endl;
	value = fix.getRawBits();	
}
//Destructor
Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits()const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
//copy assignment operator
Fixed& Fixed::operator=(const Fixed& fix)
{
	std::cout<<"Copy Assignment operator called"<<std::endl;
	if (this != &fix)
	{
		this->setRawBits(fix.getRawBits());
	}
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:57:02 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/16 10:57:02 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
	int value;
	const static int bits = 8;
	public:
	Fixed();
	Fixed(const Fixed& fix);
	Fixed& operator=(const Fixed& fix);
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed& fix);
	bool operator<(const Fixed& fix);
	bool operator>=(const Fixed& fix);
	bool operator<=(const Fixed& fix);
	bool operator==(const Fixed& fix);
	bool operator!=(const Fixed& fix);

	Fixed operator+(const Fixed& fix) const;
	Fixed operator-(const Fixed& fix) const;
	Fixed operator*(const Fixed& fix) const;
	Fixed operator/(const Fixed& fix) const;

	Fixed& operator++(void);//pre increment
	Fixed operator++(int);//post increment
	Fixed& operator--(void);//pre decrement
	Fixed operator--(int);//post decrement

	//static member function- they belong to the class, accessed using classname
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

};
std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);


#endif
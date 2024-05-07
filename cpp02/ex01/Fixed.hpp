/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:25:25 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/13 21:25:25 by fabdul-k         ###   ########.fr       */
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

};
std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);


#endif
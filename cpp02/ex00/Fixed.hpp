/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:42:22 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/12 23:42:22 by fabdul-k         ###   ########.fr       */
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
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

};


#endif
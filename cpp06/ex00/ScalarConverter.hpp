/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:46:29 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/10 08:46:29 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <cerrno>
#include <cfloat>

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(ScalarConverter& copy);
	ScalarConverter& operator=(ScalarConverter& copy);
	~ScalarConverter();

	public:
	static void convert(std::string str);
};



#endif
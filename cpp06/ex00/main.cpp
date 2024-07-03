/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:21:31 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/20 07:21:31 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::string str = argv[1];
		ScalarConverter::convert(str);
	}
	else
		std::cout<<"USAGE: ./convert <toconvert>"<<std::endl;
}
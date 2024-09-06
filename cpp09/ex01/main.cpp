/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:28:57 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/08/29 10:28:57 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cout<<"Error: Usage is : ./RPN \"expression\""<<std::endl;
		return 1;
	}

	RPN exp;
	if (!exp.check_expression(argv[1]))
	{
		std::cout<<"Error"<<std::endl;
		return 1;
	}
	try
	{
		exp.evaluateexp(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

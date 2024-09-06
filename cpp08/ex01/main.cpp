/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:42:20 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/07/06 17:42:20 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>


int main()
{
	Span sp(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(15);
	}
	catch(const std::exception &e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		Span big(10000);

		std::vector<int> copy(10000);
		std::srand(std::time(0));
		std::generate(copy.begin(), copy.end(), std::rand);

		big.fill_inrange(copy.begin(), copy.end());
		std::cout << big.shortestSpan() << std::endl;
		std::cout << big.longestSpan() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}
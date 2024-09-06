/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:23:02 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/07/29 08:23:02 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cerr<<"Error: could not open the file."<<std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange btc;
		btc.init_bitcoinmap();
		btc.validate_inputfile(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:27:45 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/07/29 08:27:45 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>


class BitcoinExchange
{
	private:
	std::map<std::string, double> datamap;
	int check_date(std::string str, std::string line);
	int check_value(std::string val, std::string line);

	public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange &copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);

	void init_bitcoinmap();
	void validate_inputfile(const char* filename);
	void generate_bitcoinvalue(std::string date, std::string value);
	void trim(std::string &str);
};

#endif
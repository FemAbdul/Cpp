/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:53:15 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/07/29 09:53:15 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange &copy):datamap(copy.datamap){}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
	{
		this->datamap = copy.datamap;
	}
	return *this;
}

void BitcoinExchange::init_bitcoinmap()
{
	std::string date;
	std::string rate;
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: Unable to open the csv file.");
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: Empty file.");
	std::string line;
	std::getline(file, line);
	if (line.compare("date,exchange_rate") != 0)
		throw std::runtime_error("Error: Invalid Header for the csv file.");
	while (std::getline(file, line))
	{
		if (line.empty())
			throw std::runtime_error("Error: Empty line in file.");
		if (line.find_first_not_of("0123456789, .-/") != std::string::npos)
			throw std::runtime_error("Error: Invalid character in file.");
		std::size_t pos = line.find(',');
		if (pos == std::string::npos)
			throw std::runtime_error("Error: Delimeter Missing");
		date = line.substr(0, pos);
		if (date.empty())
			throw std::runtime_error("Error: Date is Missing");
		rate = line.substr(pos + 1);
		std::istringstream iss(rate);
		double value;
		if (!(iss >> value))
			throw std::runtime_error("Error: Invalid value in line.");
		datamap.insert(std::make_pair(date, value));
	}
	file.close();
}

bool check_leapyear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int BitcoinExchange::check_date(std::string str, std::string line)
{
	std::string date;

	date = str.substr(0, 10);
	if (str.size() != 11 || date[4] != '-' || date[7] != '-' || str[10] != ' ')
	{
		std::cout<<"Error: bad input => "<<line<<std::endl;
		return (0);
	}
	if (date.find_first_not_of("0123456789-") != std::string::npos)
	{
		std::cout<<"Error: bad input => "<<line<<std::endl;
		return (0);
	}
	if (date < "2009-01-02")
	{
		std::cout << "Error: date out of range." << std::endl;
		return (0);
	}

	int year, month, day;
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009 || month < 1 || month > 12
	|| day < 1 || day > 31
	|| (check_leapyear(year) && month == 2 && day > 29)
	|| (!check_leapyear(year) && month == 2 && day > 28) 
	|| (month == 4 && day > 30)	|| (month == 6 && day > 30)
	|| (month == 9 && day > 30) || (month == 11 && day > 30))
	{
		std::cout<<"Error: bad input => "<<line<<std::endl;
		return (0);
	}
	return (1);
}

int BitcoinExchange::check_value(std::string val, std::string line)
{
	if (val.empty())
	{
		std::cout<<"Error: bad input => "<<line<<std::endl;
		return (0);
	}

	std::istringstream str(val);
	double value;
	if (!(str >> value))
	{
		std::cout<<"Error: bad input => "<<line<<std::endl;
		return (0);
	}
	std::string remaining;
    if (str >> remaining)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return 0;
    }
	if (value > 1000)
	{
		std::cout<<"Error: too large a number."<<std::endl;
		return (0);
	}
	if (value < 0)
	{
		std::cout<<"Error: not a positive number."<<std::endl;
		return (0);
	}
	return (1);
}
void BitcoinExchange::trim(std::string &str)
{
	std::string::iterator it = str.begin();

	while (it != str.end() && std::isspace(*it))
		++it;
	str.erase(str.begin(), it);

	std::string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend() && std::isspace(*rit))
		++rit;

	str.erase(rit.base(), str.end());
}

void BitcoinExchange::generate_bitcoinvalue(std::string date, std::string value)
{
	double rate;
	trim(date);
	trim(value);
	std::istringstream iss(value);
	iss >> rate;

	std::map<std::string, double>::iterator it = datamap.lower_bound(date);
	if (it->first != date)
		it--;
	double exchange = rate * it->second;
	std::cout<<std::fixed<<std::setprecision(3);
	std::cout<<date<<" => "<<value<<" = "<<exchange<<std::endl;
}


void BitcoinExchange::validate_inputfile(const char* filename)
{
	std::ifstream ifile(filename);
	std::string line, date, value;

	if (!ifile.is_open())
		throw std::runtime_error("Error: could not open file.");
	if (ifile.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: Empty file.");
	
	std::getline(ifile, line);
	trim(line);
	if (line.compare("date | value") != 0)
		throw std::runtime_error("Error: Invalid header.");
	while (std::getline(ifile, line))
	{
		if (line.empty())
			continue;
		std::istringstream str(line);
		if (std::getline(str,date,'|') && std::getline(str, value, '|'))
		{
			if (check_date(date, line) && check_value(value, line))
				generate_bitcoinvalue(date, value);
		}
		else
		{
			std::cout<<"Error: bad input => "<<line<<std::endl;
		}
	}
}



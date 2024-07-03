/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:45:59 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/10 08:45:59 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& copy)
{
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

enum type {
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	ERROR
};

static bool isChar(std::string str)
{
	if (str.length() != 1 || !isprint(str[0]) || isdigit(str[0]))
		return false;
	return true;
}

static bool isInt(std::string str)
{
	for (size_t i = str[0] == '-'? 1 : 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

static bool isFloat(std::string str)
{
	bool point = false;

	if (str == "+inff" || str == "inff" ||str == "-inff" || str == "nanf")
		return true;
	if (str[str.length() - 1] != 'f')
		return false;
	for (size_t i = str[0] == '-'? 1 : 0; i < str.length() - 1; i++)
	{
		if ((str[i] == '.' && point) || (!isdigit(str[i]) && str[i] != '.'))
			return false;
		if (str[i] == '.')
			point = true;
	}
	return true;
}

static bool isDouble(std::string str)
{
	bool point = false;
	
	if (str == "+inf" || str == "inf" || str == "-inf" || str == "nan")
		return true;
	for (size_t i = str[0] == '-'? 1 : 0; i < str.length(); i++)
	{
		if ((str[i] == '.' && point) || (!isdigit(str[i]) && str[i] != '.'))
			return false;
		if (str[i] == '.')
			point = true;
	}
	return true;
}

static type type_identify(std::string str)
{
	if (isChar(str))
		return CHAR_TYPE;
	if (isInt(str))
		return INT_TYPE;
	else if (isFloat(str))
		return FLOAT_TYPE;
	else if (isDouble(str))
		return DOUBLE_TYPE;
	else
		return ERROR;
}

void convert_char(char c)
{
	std::cout<<"char: '"<<c<<"'"<<std::endl;
	std::cout<<"int: "<<static_cast <int> (c)<<std::endl;
	std::cout<<"float: "<<static_cast <float> (c)<<".0f"<<std::endl;
	std::cout<<"double: "<<static_cast <double> (c)<<".0"<<std::endl;
}

void convert_int(std::string str)
{
	long int tolong;
	int toInt;
	float toFloat;
	char *end;

	tolong = std::strtol(str.c_str(), &end, 10);
	if (tolong < INT_MIN || tolong > INT_MAX || *end != '\0')
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		errno = 0;
		toFloat = std::strtof(str.c_str(), &end);
		if (*end !='\0' || errno == ERANGE)
			std::cout<<"float: impossible"<<std::endl;
		else
			std::cout<<"float: "<<toFloat<<".0f"<<std::endl;
		errno = 0;
		double toDb = std::strtod(str.c_str(), &end);
		if (*end !='\0' || errno == ERANGE)
			std::cout<<"double: impossible"<<std::endl;
		else
			std::cout<<"double: "<<toDb<<std::endl;
	}
	else
	{
		toInt = static_cast<int>(tolong);
		if (toInt >= 0 && toInt <= 127 && isprint(toInt))
			std::cout<<"char: '"<<static_cast<char>(toInt)<<"'"<<std::endl;
		else	
			std::cout<<"char: Non Displayable"<<std::endl;
		std::cout<<"int: "<<toInt<<std::endl;
		std::cout<<"float: "<<static_cast<float>(toInt)<<".0f"<<std::endl;
		std::cout<<"double: "<<static_cast<double>(toInt)<<".0"<<std::endl;
	}
}

void convert_float(std::string str)
{
	float toFloat;
	char *end;

	errno = 0;
	toFloat = std::strtof(str.c_str(), &end);
	if (toFloat != 0 && (toFloat < FLT_MIN || toFloat > FLT_MAX || errno == ERANGE))
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: impossible"<<toFloat<<std::endl;
		errno = 0;
		double toDb = std::strtod(str.c_str(), &end);
		if (errno == ERANGE)
			std::cout<<"double: impossible"<<std::endl;
		else
			std::cout<<"double: "<<toDb<<std::endl;
	}
	else
	{
		if (toFloat < 0 || toFloat > 127 || !isprint(static_cast<int>(toFloat)))
			std::cout<<"char: impossible"<<std::endl;
		else
			std::cout<<"char: '"<<static_cast<char>(toFloat)<<"'"<<std::endl;
		if (toFloat < INT_MIN || toFloat > INT_MAX)
			std::cout<<"int: impossible"<<std::endl;
		else
			std::cout<<"int: "<<static_cast<int>(toFloat)<<std::endl;
		if (toFloat == (static_cast<int>(toFloat)))
		{
			std::cout<<"float: "<<toFloat<<".0f"<<std::endl;
			std::cout<<"double: "<<static_cast<double>(toFloat)<<".0"<<std::endl;
		}
		else
		{
			std::cout<<"float: "<<toFloat<<"0f"<<std::endl;
			std::cout<<"double: "<<static_cast<double>(toFloat)<<"0"<<std::endl;
		}
	}
}

void convert_double(std::string str)
{
	char *end;
	double toDb = std::strtod(str.c_str(), &end);
	if (toDb != 0 && (toDb < FLT_MIN || toDb > FLT_MAX || errno == ERANGE))
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: impossible"<<std::endl;
		std::cout<<"double: impossible"<<std::endl;
	}
	else
	{
		if (!isprint(static_cast<int>(toDb)))
			std::cout<<"char: impossible"<<std::endl;
		else
			std::cout<<"char: '"<<static_cast<char>(toDb)<<"'"<<std::endl;
		if (toDb < INT_MIN || toDb> INT_MAX)
			std::cout<<"int: impossible"<<std::endl;
		else
			std::cout<<"int: "<<static_cast<int>(toDb)<<std::endl;
		if (toDb < FLT_MIN || toDb > FLT_MAX)
			std::cout<<"float: impossible"<<std::endl;
		else if (toDb == (static_cast<int>(toDb)))
		{
			std::cout<<"float: "<<toDb<<".0f"<<std::endl;
			std::cout<<"double: "<<static_cast<double>(toDb)<<".0"<<std::endl;
		}
		else
		{
			std::cout<<"float: "<<toDb<<"0f"<<std::endl;
			std::cout<<"double: "<<toDb<<"0"<<std::endl;
		}
	}
}

bool check_floatpseudo(std::string str)
{
	if (str == "+inff" || str == "inff" || str == "-inff" || str == "nanf")
		return true;
	return false;
}

bool check_doublepseudo(std::string str)
{
	if (str == "+inf" || str == "inf" || str == "-inf" || str == "nan")
		return true;
	return false;
}

void convert_pseudo(std::string str)
{
	std::cout<<"char: impossible"<<std::endl;
	std::cout<<"int: impossible"<<std::endl;
	if (check_floatpseudo(str) == true)
	{
		std::cout<<"float: "<<str<<std::endl;
		std::cout<<"double: "<<str.substr(0, str.length() - 1)<<std::endl;
	}
	else
	{
		std::cout<<"float: "<<str<<"f"<<std::endl;
		std::cout<<"double: "<<str<<std::endl;
	}
}

void ScalarConverter::convert(std::string str)
{
	type strtype;

	strtype = type_identify(str);
	switch(strtype)
	{
		case CHAR_TYPE: convert_char(str[0]);
						break;
		case INT_TYPE: convert_int(str);
						break;
		case FLOAT_TYPE:if (check_floatpseudo(str))
							convert_pseudo(str);
						else 
							convert_float(str);
						break;
		case DOUBLE_TYPE:if (check_doublepseudo(str))
							convert_pseudo(str);
						else
							convert_double(str);
						break;
		default : std::cout<<"Invalid type"<<std::endl;
	}

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 07:51:59 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/08/29 07:51:59 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &copy)
{
	operandstack = copy.operandstack; 
}

RPN& RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		this->operandstack = copy.operandstack;
	return (*this);
}

RPN::~RPN(){}

bool RPN::check_expression(std::string str)
{
	int num_token = 0;
	int num_operands = 0;
	for (int i = 0; i < (int)str.length(); i++)
	{
		char c = str[i];
		if (c == '+' || c == '-' || c == '*' || c == '/')
			num_token++;
		else if (isdigit(c))
			num_operands++;
		else if (c != ' ')
			return false;
	}
	
	if (num_operands != (num_token + 1) || num_operands == 0 || num_token == 0)
		return false;
	return true;
}

void RPN::evaluateexp(std::string str)
{
	char c;

	for (int i = 0; i < (int)str.length();i++)
	{
		c = str[i];
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (operandstack.size() < 2)
				throw InvalidException();
			int num_2 = operandstack.top();
			operandstack.pop();
			int num_1 = operandstack.top();
			operandstack.pop();
		
			int res = 0;
			if (c == '/' && num_2 == 0)
				throw DivisionbyZero();
			if (c == '+')
				res = num_1 + num_2;
			else if (c == '-')
				res = num_1 - num_2;
			else if (c == '*')
				res = num_1 * num_2;
			else if (c == '/')
				res = num_1 / num_2;
				
			if (res > INT_MAX || res < INT_MIN)
				throw InvalidException();
			operandstack.push(res);
		}
		else if (isdigit(c))
			operandstack.push(c - '0');
	}
	if (operandstack.size() != 1)
		throw InvalidException();

	std::cout<<operandstack.top()<<std::endl;
	operandstack.pop();
}

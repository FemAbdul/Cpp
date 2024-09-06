/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 07:52:11 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/08/29 07:52:11 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <climits>
#include <exception>

class InvalidException:public std::exception
{
	public:
	virtual const char *what()const throw()
	{
		return ("Invalid expression");
	}
};

class DivisionbyZero:public std::exception
{
	public:
	virtual const char *what()const throw()
	{
		return ("Division By Zero");
	}
};


class RPN
{
	private:
	std::stack<int> operandstack;

	public:
	RPN();
	~RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);

	bool check_expression(std::string str);
	void evaluateexp(std::string str);

};




#endif
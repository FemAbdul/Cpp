/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 07:57:50 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/21 07:57:50 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include<exception>

Base* generate(void)
{
	int n;
	Base *b;

	n = std::rand() % 3;
	if (n == 0)
		b = new A;
	else if (n == 1)
		b = new B;
	else
		b = new C;
	return (b);
}

void identify(Base* p)
{
	if (dynamic_cast <A*> (p) != NULL)
		std::cout<<"Identified as an object of Class A"<<std::endl;
	else if (dynamic_cast <B*> (p) != NULL)
		std::cout<<"Identified as an object of Class B"<<std::endl;
	else if (dynamic_cast <C*> (p) != NULL)
		std::cout<<"Identified as an object of Class C"<<std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout<<"Identified as an object of Class A"<<std::endl;
		(void)a;
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout<<"Identified as an object of Class B"<<std::endl;
		(void)b;
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout<<"Identified as an object of Class C"<<std::endl;
		(void)c;
		return;
	}
	catch(const std::exception& e)
	{}
}

int main()
{
	std::srand(std::time(0));
	Base *b;

	b = generate();
	identify(b);
	identify(*b);
	delete b;
}
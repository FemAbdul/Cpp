/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:41:18 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/05/20 13:41:18 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{	
	try
	{
		Bureaucrat b("low", 150);
		std::cout << b<<std::endl;
		b.decGrade();
		std::cout << b <<std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	try
	{
		Bureaucrat c("high", 1);
		std::cout<< c<<std::endl;
		c.incGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}
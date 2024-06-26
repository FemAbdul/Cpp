/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:41:18 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/05/20 13:41:18 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{	
	try
	{
		Bureaucrat b("B1", 5);
		std::cout << b<<std::endl;
		ShrubberyCreationForm f("Home");
		RobotomyRequestForm r("Home");
		PresidentialPardonForm p("Tod");
		
		std::cout <<std::endl<< f <<std::endl;
		b.executeForm(f);
		b.signForm(f);
		b.executeForm(f);
		
		std::cout <<std::endl<< p <<std::endl;
		b.signForm(p);
		b.executeForm(p);

		std::cout <<std::endl<< r <<std::endl;
		b.signForm(r);
		b.executeForm(r);
		b.executeForm(r);
		std::cout <<std::endl;

		Bureaucrat b1("B2", 144);
		std::cout <<b1;
		ShrubberyCreationForm f1("SecondHome");
		std::cout <<std::endl<< f1 <<std::endl;
		b1.signForm(f1);
		b1.executeForm(f1);

	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}
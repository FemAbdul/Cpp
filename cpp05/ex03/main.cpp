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
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{	
	Form* rrf;
	Intern someRandomIntern;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	try
	{
		Bureaucrat b("B1", 5);
		std::cout << b<<std::endl;
		b.signForm(*rrf);
		b.executeForm(*rrf);

		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
		delete rrf;
	}
}
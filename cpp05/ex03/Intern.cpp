/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 08:38:48 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/07 08:38:48 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(Intern& copy)
{
	*this = copy;
}

Intern& Intern::operator=(Intern& copy)
{
	(void)copy;
	return *this;
}

Intern::~Intern()
{}

Form* Intern::robotomyform(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::presidentialform(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form* Intern::shrubberyform(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeForm(std::string Formname, std::string target)
{
	Form* obj;
	obj = NULL;
	std::string names[3] = {"robotomy request", "presidential pardon",
							"shrubbery creation"};
	func_ptr form[3] = {&Intern::robotomyform,
					&Intern::presidentialform,
					&Intern::shrubberyform};

	for (int i = 0; i < 3 ; i++)
	{
		if (Formname == names[i])
		{
			obj = (this->*form[i])(target);
			std::cout<<"Intern created Form "<<names[i]<<std::endl;
			return obj;
		}
	}
	std::cout<<"Intern could not create form "<<Formname<<std::endl;
	return NULL;
}
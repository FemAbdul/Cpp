/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:09:41 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/05 16:09:41 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& starget):Form("PresidentialPardonForm", starget, 25, 5)
{
	std::cout<<"Presidential Pardon Form constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):Form(copy.getName(), copy.getTarget(), copy.getSignGrade(), copy.getExecuteGrade())
{
	std::cout<<"Presidential Pardon Form copy constructor called"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		Form::operator=(copy);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"Presidential Pardon Form Destructor"<<std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
	{
		std::cout<<"Cannot execute form as Execution grade is too low!!"<<std::endl;
		throw Form::GradeTooLowException();
	}
	else if (!this->getSigned())
	{
		std::cout<<"Cannot execute form as it is not signed"<<std::endl;
		return ;
	}
	else
	{	
		std::cout<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
	}
}
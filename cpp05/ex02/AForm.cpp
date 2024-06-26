/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:02:49 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/03 08:02:49 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, std::string target, int sign, int exec):name(name), target(target), isSigned(false), grade_sign(sign), grade_execute(exec)
{
	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy):name(copy.getName()), target(copy.getTarget()), isSigned(copy.getSigned()), grade_sign(copy.getSignGrade()), grade_execute(copy.getExecuteGrade())
{
	std::cout<<"Copy Constructor called"<<std::endl;
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		this->isSigned = copy.getSigned();
	}
	return *this;
}

AForm::~AForm()
{
	std::cout<<"AForm destructor called"<<std::endl;
}

std::string AForm::getName(void)const
{
	return (name);
}

std::string AForm::getTarget(void)const
{
	return (target);
}

int AForm::getSignGrade(void)const
{
	return (grade_sign);
}

int AForm::getExecuteGrade(void)const
{
	return (grade_execute);
}

bool AForm::getSigned(void)const
{
	return isSigned;
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->grade_sign)
	{
		this->isSigned = true;
	}
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os,AForm& f)
{
	os<< "AForm "<<f.getName()<<", require  Sign Grade "<<f.getSignGrade()<<", Execution Grade "<<f.getExecuteGrade()<<" signed = "<<f.getSigned();
	return os;
}
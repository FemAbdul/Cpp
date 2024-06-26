/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:02:49 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/03 08:02:49 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, std::string target, int sign, int exec):name(name), target(target), isSigned(false), grade_sign(sign), grade_execute(exec)
{
	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy):name(copy.getName()), target(copy.getTarget()), isSigned(copy.getSigned()), grade_sign(copy.getSignGrade()), grade_execute(copy.getExecuteGrade())
{
	std::cout<<"Copy Constructor called"<<std::endl;
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
	{
		this->isSigned = copy.getSigned();
	}
	return *this;
}

Form::~Form()
{
	std::cout<<"Form destructor called"<<std::endl;
}

std::string Form::getName(void)const
{
	return (name);
}

std::string Form::getTarget(void)const
{
	return (target);
}

int Form::getSignGrade(void)const
{
	return (grade_sign);
}

int Form::getExecuteGrade(void)const
{
	return (grade_execute);
}

bool Form::getSigned(void)const
{
	return isSigned;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->grade_sign)
	{
		this->isSigned = true;
	}
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os,Form& f)
{
	os<< "Form "<<f.getName()<<", require  Sign Grade "<<f.getSignGrade()<<", signed = "<<f.getSigned();
	return os;
}
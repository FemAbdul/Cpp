/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:40:00 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/02 10:40:00 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():name("default"), isSigned(false),grade(150)
{
	std::cout<<"Form Default constructor"<<std::endl;
}

Form::Form(std::string name, int grade):name(name), isSigned(false), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout<<"Form Constructor called"<<std::endl;
}

Form::Form(const Form& copy):name(copy.getName()), isSigned(copy.getSigned()), grade(copy.getGrade())
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

int Form::getGrade(void)const
{
	return grade;
}

bool Form::getSigned(void) const
{
	return isSigned;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->grade)
	{
		this->isSigned = true;
	}
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os,Form& f)
{
	os<< "Form "<<f.getName()<<", require Grade "<<f.getGrade()<<", signed = "<<f.getSigned();
	return os;
}
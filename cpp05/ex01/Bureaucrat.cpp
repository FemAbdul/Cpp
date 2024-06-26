/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:21:51 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/05/20 14:21:51 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
	std::cout<<"Bureaucrat default constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string bname, int bgrade): name(bname), grade(bgrade)
{
	if (bgrade < 1)
		throw GradeTooHighException();
	if (bgrade > 150)
		throw GradeTooLowException();
	std::cout<<"Bureaucrat "<<bname<<" constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name(copy.name), grade(copy.grade)
{
	std::cout<<"Bureaucrat copy constructor called"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &copy)
	{
		this->grade = copy.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout<<"Bureaucrat destructor called"<<std::endl;
}

int Bureaucrat::getGrade(void)
{
	return (grade);
}

const std::string Bureaucrat::getName(void)
{
	return (name);
}

 void Bureaucrat::incGrade(void)
 {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade = grade - 1;
 }

 void Bureaucrat::decGrade(void)
 {
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade = grade + 1; 
 }

std::ostream& operator<<(std::ostream& o, Bureaucrat& b)
{
	o <<"Bureaucrat "<<b.getName()<<",  grade "<<b.getGrade();
	return o;
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout<<"Bureaucrat " <<this->getName()<< " signed form "<< f.getName()<<std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cout<<"Bureaucrat "<< this->getName() <<" could not sign Form "<<f.getName()<<" because "<<e.what()<<std::endl;
	}
}
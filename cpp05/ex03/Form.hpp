/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:03:01 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/03 08:03:01 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form 
{
	private:
	const std::string name;
	const std::string target;
	bool isSigned;
	const int grade_sign;
	const int grade_execute;
	Form(void);
	
	public:
	Form(std::string name, std::string target,int grade_sign, int grade_execute);
	Form(const Form& copy);
	Form& operator=(const Form& copy);
	
	virtual ~Form();
	virtual void execute(Bureaucrat const & executor) const = 0;

	std::string getName(void)const;
	std::string getTarget(void)const;
	int getSignGrade(void)const;
	int getExecuteGrade(void)const;
	bool getSigned(void)const;
	void beSigned(Bureaucrat& b);

	class GradeTooHighException:public std::exception
	{
		public:
		virtual const char* what()const throw()
		{
			return "Form Grade Too High Exception";
		}
	};

	class GradeTooLowException:public std::exception
	{
		public:
		virtual const char* what()const throw()
		{
			return "Form Grade Too Low Exception";
		}
	};
};

std::ostream& operator<<(std::ostream& os,Form& f);

#endif
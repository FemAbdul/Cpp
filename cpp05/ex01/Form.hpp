/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:05:14 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/05/31 10:05:14 by fabdul-k         ###   ########.fr       */
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
	bool isSigned;
	const int grade;

	public:
	Form(void);
	Form(std::string name, int grade);
	Form(const Form& copy);
	Form& operator=(const Form& copy);
	~Form();
	std::string getName(void)const;
	int getGrade(void)const;
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
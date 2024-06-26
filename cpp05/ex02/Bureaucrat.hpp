/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:43:31 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/05/20 13:43:31 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;
class Bureaucrat
{
	private:
	const std::string name;
	int grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string bname, int bgrade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	~Bureaucrat(void);
	const std::string getName(void);
	int getGrade(void)const;
	void incGrade(void);
	void decGrade(void);
	void signForm(AForm& f);
	void executeForm(const AForm& form);

	class GradeTooHighException:public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Grade Too High Exception";
		}
	};
	class GradeTooLowException:public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Grade Too Low Exception";
		}
	};
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& b);

#endif
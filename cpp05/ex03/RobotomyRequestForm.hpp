/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:35:36 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/05 14:35:36 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"

class RobotomyRequestForm:public Form
{
	private:
	RobotomyRequestForm();

	public:
	RobotomyRequestForm(const std::string& starget);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
	~RobotomyRequestForm();

	void execute(const Bureaucrat& executor) const;
};


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 08:38:43 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/07 08:38:43 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"


class Intern
{
	public:
	Intern();
	Intern(Intern& copy);
	Intern& operator=(Intern& copy);
	~Intern();

	Form* robotomyform(std::string target);
	Form* presidentialform(std::string target);
	Form* shrubberyform(std::string target);
	Form* makeForm(std::string Formname, std::string target);
};

typedef Form* (Intern::*func_ptr)(std::string);

#endif
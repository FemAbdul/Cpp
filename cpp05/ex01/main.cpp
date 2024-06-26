/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:41:18 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/05/20 13:41:18 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{	
	try
	{
		Bureaucrat b("B1", 1);
		std::cout << b<<std::endl;
		Form f("Form1", 148);
		std::cout << f <<std::endl;
		b.signForm(f);
		std::cout << f <<std::endl;
		std::cout <<std::endl;

		Bureaucrat b1("B2", 150);
		std::cout<< b1<<std::endl;
		Form f1("Form2", 148);
		std::cout << f1 <<std::endl;
		b1.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:26:03 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/08 09:26:03 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout<<"The memory address of brain is: "<<&brain<<std::endl;
	std::cout<<"The memory address held by stringPTR is: "<<stringPTR<<std::endl;
	std::cout<<"The memory address held by stringREF is: "<<&stringREF<<std::endl;
	std::cout<<std::endl;
	std::cout<<"The value of string variable is: "<<brain<<std::endl;
	std::cout<<"The value pointed to by stringPTR is: "<<*stringPTR<<std::endl;
	std::cout<<"The value pointed to by stringREF is: "<<stringREF<<std::endl;

}
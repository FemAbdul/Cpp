/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:52:41 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/02/27 09:52:41 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include "PhoneBook.hpp"

int main()
{
	std::string choice;
	PhoneBook ph;

	std::cout<<"---Welcome to your phonebook---"<<std::endl;
	std::cout<<"1. ADD"<<std::endl<<"2. SEARCH"<<std::endl;
	std::cout<<"3. EXIT"<<std::endl;
	
	while (1)
	{
		std::cout<<"Enter your choice:"<<std::flush;
		std::cin>>choice;

		if (choice == "ADD")
			ph.add_contact();
		else if(choice == "SEARCH")
		{
			
			ph.search();
		}
		else if (choice == "EXIT")
		{
			std::cout<<"exiting"<<std::endl;
			return (0);
		}
		std::cout<<std::endl;
	}
}
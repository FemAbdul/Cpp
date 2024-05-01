/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:08:20 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/02/29 09:08:20 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->oldest = 0;
}

void PhoneBook::add_contact(void)
{
	Contact new_contact;
	std::string str;
	
	std::cin.ignore(1000, '\n');
	std::cout<<"---Enter Detailsof New Contact---"<<std::endl;
	std::cout<<"Enter First Name:";
	getline(std::cin, str);
	new_contact.set_first(str);
	std::cout<<"Enter Last Name:";
	std::getline(std::cin, str);
	new_contact.set_last(str);
	std::cout<<"Enter Nick Name:";
	getline(std::cin, str);
	new_contact.set_nn(str);
	while (1)
	{
		std::cout<<"Enter Phone Number:";
		getline(std::cin, str);
		if (str.empty() || str.find_first_not_of("0123456789") != std::string::npos) //==npos if noting found
		{
			std::cin.clear();
			std::cout<<"Invalid phone Number!!"<<std::endl;
		}
		else
		{
			new_contact.set_phone(str);
			break ;
		}
	}
	std::cout<<"Enter Darkest Secret:";
	getline(std::cin, str);
	new_contact.set_secret(str);
	if (this->index < 8) //for 8 contacts it will be 0,1,2..7
		this->index++;
	else
	{
		if (this->oldest == 8) //max
			this->oldest = 0;
		this->contacts[oldest] = new_contact;
		this->oldest++;
		return;
	}
	this->contacts[index - 1] = new_contact;
}

std::string check_field(std::string text)
{
	std::string field;

	field = text.substr(0, 10);
	if (text.length() > 10)
		field[9] = '.';
	return (field);
}

void PhoneBook::display_list(void)
{
	std::cout<<std::endl;
	std::cout<<".__________.__________.__________.__________."<<std::endl;
	std::cout<<"|     Index|First Name| Last Name| Nick Name|"<<std::endl;
	std::cout<<"|----------|----------|----------|----------|";
	std::cout<<std::endl;
	for (int i = 0; i < this->index; i++)
	{
		std::cout<<"|"<<std::setfill(' ')<<std::setw(10);
		std::cout<<(i + 1);
		std::cout<<"|"<<std::setfill(' ')<<std::setw(10);
		std::cout<<check_field(this->contacts[i].get_first());
		std::cout<<"|"<<std::setfill(' ')<<std::setw(10);
		std::cout<<check_field(this->contacts[i].get_last());
		std::cout<<"|"<<std::setfill(' ')<<std::setw(10);
		std::cout<<check_field(this->contacts[i].get_nn())<<"|";
		std::cout<<std::endl;
	}
	std::cout<<"|__________|__________|__________|__________|"<<std::endl;
}

void PhoneBook::search(void)
{
	int num = 0;

	if (this->index == 0)
	{
		std::cout<<"PhoneBook is Empty!!!"<<std::endl;
		return ;
	}
	else
		this->display_list();
	std::cout<<std::endl<<"Enter the index of Contact to display : ";
	std::cin>>num;
	if ((std::cin.fail()) || num <= 0 || num > this->index)
	{
		std::cout<<std::endl<<"INCORRECT INDEX!!!!"<<std::endl;
		std::cin.clear(); // Clear error state
    	std::cin.ignore(1000, '\n');
		return ;
	}
	std::cout<<std::endl<<"First Name"<<":";
	std::cout<<this->contacts[num - 1].get_first()<<std::endl;
	std::cout<<"Last Name"<<":";
	std::cout<<this->contacts[num - 1].get_last()<<std::endl;
	std::cout<<"Nick Name"<<":";
	std::cout<<this->contacts[num - 1].get_nn()<<std::endl;
	std::cout<<"Phone Number"<<":";
	std::cout<<this->contacts[num - 1].get_phone()<<std::endl;
	std::cout<<"Darkest Secret"<<":";
	std::cout<<this->contacts[num - 1].get_secret()<<std::endl;
}
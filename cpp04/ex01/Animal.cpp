/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:06:20 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/23 08:06:20 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include<iostream>

Animal::Animal()
{
	type = "Animal";
	std::cout<<"Animal Constructor called"<<std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout<<"Animal Copy Constructor called"<<std::endl;
	this->type = copy.type;
}

Animal& Animal::operator=(const Animal& copy)
{
	std::cout<<"Animal Copy Assignment operator called"<<std::endl;
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

Animal::~Animal()
{
	std::cout<<"Animal Destructor called!"<<std::endl;
}

void Animal::makeSound() const
{
	std::cout<<"Some Animal sound!"<<std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}
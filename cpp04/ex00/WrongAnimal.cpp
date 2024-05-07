/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:56:43 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/24 19:56:43 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include<iostream>

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout<<"WrongAnimal Copy Constructor called"<<std::endl;
	this->type = copy.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout<<"WrongAnimal Copy Assignment operator called"<<std::endl;
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal Destructor called!"<<std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout<<"Some WrongAnimal sound!"<<std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}
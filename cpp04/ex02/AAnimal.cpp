/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:06:20 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/23 08:06:20 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include<iostream>

AAnimal::AAnimal()
{
	type = "AAnimal";
	std::cout<<"AAnimal Constructor called"<<std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	std::cout<<"AAnimal Copy Constructor called"<<std::endl;
	this->type = copy.type;
}

AAnimal& AAnimal::operator=(const AAnimal& copy)
{
	std::cout<<"AAnimal Copy Assignment operator called"<<std::endl;
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout<<"AAnimal Destructor called!"<<std::endl;
}

void AAnimal::makeSound() const
{
	std::cout<<"Some AAnimal sound!"<<std::endl;
}

std::string AAnimal::getType(void) const
{
	return this->type;
}
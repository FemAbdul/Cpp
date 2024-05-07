/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:06:49 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/23 08:06:49 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog():Animal()
{
	std::cout<<"Dog Constructor called"<<std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& copy):Animal()
{
	std::cout<<"Dog Copy Constructor called"<<std::endl;
	this->type = copy.type;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout<<"Dog Copy Assignment operator called"<<std::endl;
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

Dog::~Dog()
{
	std::cout<<"Dog Destructor called!"<<std::endl;
}

void Dog::makeSound() const
{
	std::cout<<"Dogs BARK!"<<std::endl;
}

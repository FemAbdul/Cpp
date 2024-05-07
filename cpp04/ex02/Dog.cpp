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

#include "AAnimal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog():AAnimal()
{
	type = "Dog";
	std::cout<<"Dog Constructor called!"<<std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy):AAnimal()
{
	std::cout<<"Dog Copy Constructor called"<<std::endl;
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout<<"Dog Copy Assignment operator called"<<std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout<<"Dog Destructor called!"<<std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout<<"Dogs BARK!"<<std::endl;
}

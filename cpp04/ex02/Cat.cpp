/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:07:34 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/23 08:07:34 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat():AAnimal()
{
	type = "Cat";
	std::cout<<"Cat Constructor called!"<<std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy):AAnimal()
{
	std::cout<<"Cat Copy Constructor called"<<std::endl;
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout<<"Cat Copy Assignment operator called"<<std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout<<"Cat Destructor called!"<<std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout<<"Cat makes MEOW sound!"<<std::endl;
}

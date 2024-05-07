/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:05:50 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/24 20:05:50 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat():WrongAnimal()
{
	std::cout<<"WrongCat Constructor called"<<std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy):WrongAnimal()
{
	std::cout<<"WrongCat Copy Constructor called"<<std::endl;
	this->type = copy.type;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout<<"WrongCat Copy Assignment operator called"<<std::endl;
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout<<"WrongCat Destructor called!"<<std::endl;
}

void WrongCat::makeSound() const
{
	std::cout<<"WrongCat makes MEOW sound!"<<std::endl;
}
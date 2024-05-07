/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:47:46 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/24 20:47:46 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout<<"Brain constructor called"<<std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout<<"Brain Copy Constructor called"<<std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
	std::cout<<"Brain Copy Assignment operator called"<<std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout<<"Brain Destructor called!"<<std::endl;
}

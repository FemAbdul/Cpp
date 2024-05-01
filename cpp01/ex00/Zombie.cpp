/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 07:11:38 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/07 07:11:38 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zname)
{
	this->name = zname;
}

Zombie::~Zombie()
{
	std::cout<<"Zombie "<<this->name<<" Destroyed!!"<<std::endl;
}
void Zombie::announce(void)
{
	std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
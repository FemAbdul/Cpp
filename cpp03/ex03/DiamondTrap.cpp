/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:24:02 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/22 09:24:02 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout<<"Default Constructor of Diamond Trap called"<<std::endl;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clapname")
{
	std::cout<<"Diamond Trap Constructor called"<<std::endl;
	this->name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy.name+"_clapname"), ScavTrap(copy), FragTrap(copy)
{
	std::cout<<"Diamond Trap Copy Constructor called"<<std::endl;
	this->name = copy.name;
	this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	std::cout<<"Diamond Trap Copy Assignment Operator called"<<std::endl;
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		this->name = copy.name;
		this->hit_points = copy.hit_points;
		this->energy_points = copy.energy_points;
		this->attack_damage = copy.attack_damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout<<"DiamondTrap Destructor called!!"<<std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout<<"Iam DiamondTrap "<<this->name<<" and ClapTrap name is "<<ClapTrap::name<<std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:38:50 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/19 20:38:50 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
	std::cout<<"ScavTrap Default constructor called!"<<std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;	
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	std::cout<<"Scavtrap Constructor called!"<<std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;	
}

ScavTrap::ScavTrap(const ScavTrap& scav):ClapTrap(scav)
{
	std::cout<<"ScavTrap Copy Constructor called!"<<std::endl;
	this->name = scav.name;
	this->hit_points = scav.hit_points;
	this->energy_points = scav.energy_points;
	this->attack_damage = scav.attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scav)
{
	if (this != &scav)
	{
		this->name = scav.name;
		this->hit_points = scav.hit_points;
		this->energy_points = scav.energy_points;
		this->attack_damage = scav.attack_damage;
	}
	std::cout<<"Copy Assignment operator called!"<<std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap Destructor called!"<<std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout<<"ScavTrap "<<this->name<<" is now in Gate keeper mode"<<std::endl;
}

void ScavTrap::attack(const std::string& target)
{	
	if (this->energy_points <= 0 || this->hit_points <= 0)
	{
		std::cout<<"ScavTrap is short of Energy points!!";
		return ;
	}
	std::cout<<"ScavTrap "<<this->name<<" attacks "<<target<<", causing "<<this->attack_damage<<" points of damage!"<<std::endl;
	this->energy_points -= 1;
}
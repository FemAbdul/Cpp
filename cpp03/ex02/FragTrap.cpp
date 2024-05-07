/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:38:50 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/19 20:38:50 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
	std::cout<<"FragTrap Default constructor called!"<<std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;	
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	std::cout<<"FragTrap Constructor called!"<<std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;	
}

FragTrap::FragTrap(const FragTrap& frag):ClapTrap(frag)
{
	std::cout<<"FragTrap Copy Constructor called!"<<std::endl;
	this->name = frag.name;
	this->hit_points = frag.hit_points;
	this->energy_points = frag.energy_points;
	this->attack_damage = frag.attack_damage;
}

FragTrap& FragTrap::operator=(const FragTrap& frag)
{
	if (this != &frag)
	{
		this->name = frag.name;
		this->hit_points = frag.hit_points;
		this->energy_points = frag.energy_points;
		this->attack_damage = frag.attack_damage;
	}
	std::cout<<"Copy Assignment operator called!"<<std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap Destructor called!"<<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout<<"FragTrap "<<this->name<<" displays a positive high fives request"<<std::endl;
}

void FragTrap::attack(const std::string& target)
{	
	if (this->energy_points <= 0 || this->hit_points <= 0)
	{
		std::cout<<"FragTrap is short of Energy points!!";
		return ;
	}
	std::cout<<"FragTrap "<<this->name<<" attacks "<<target<<", causing "<<this->attack_damage<<" points of damage!"<<std::endl;
	this->energy_points -= 1;
}
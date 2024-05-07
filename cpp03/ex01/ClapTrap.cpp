/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:45:18 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/19 08:45:18 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout<<"ClapTrap Default Constructor called!"<<std::endl;
}

ClapTrap::ClapTrap(std::string name):name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout<<"ClapTrap Constructor "<<name<<" called!!"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clap)
{
	this->name = clap.name;
	this->hit_points = clap.hit_points;
	this->energy_points = clap.energy_points;
	this->attack_damage = clap.attack_damage;
	std::cout<<"Copy Constructor called"<<std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clap)
{
	if (this != &clap)
	{
		this->name = clap.name;
		this->hit_points = clap.hit_points;
		this->energy_points = clap.energy_points;
		this->attack_damage = clap.attack_damage;
	}
	std::cout<<"Copy Assignment operator called!"<<std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap Destructor called!!"<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy_points <= 0 || this->hit_points <= 0)
	{
		std::cout<<"ClapTrap is short of Energy points!!";
		return ;
	}
	std::cout<<"ClapTrap "<<this->name<<" attacks "<<target<<", causing "<<this->attack_damage<<" points of damage!"<<std::endl;
	this->energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->hit_points || this->hit_points== 0 || this->energy_points <= 0)
	{
		std::cout<<"ClapTrap "<<this->name<<" died!!"<<std::endl;
		this->hit_points = 0;
		return ;
	}
	std::cout<<"ClapTrap "<<this->name<<" took damage of "<<amount<<std::endl;
	this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points <= 0 || this->hit_points <= 0)
	{
		std::cout<<"ClapTrap is in short of Energy points!!";
		return ;
	}
	std::cout<<this->name<<" repaired and gained "<<amount<<" hit_points!"<<std::endl;
	this->energy_points -= 1;
	this->hit_points += amount;
}

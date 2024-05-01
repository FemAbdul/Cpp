/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:59:13 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/10 19:59:13 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include<iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
	std::string name;
	Weapon *weapon;

	public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack(void);
};

#endif
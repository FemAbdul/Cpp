/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:50:05 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/22 07:50:05 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap:public ScavTrap, public FragTrap
{
	private:
	std::string name;
	
	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& copy);
	DiamondTrap &operator=(const DiamondTrap& copy);
	~DiamondTrap();

	void whoAmI();
	using ScavTrap::attack;
};



#endif

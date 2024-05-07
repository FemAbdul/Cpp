/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:10:24 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/19 20:10:24 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap:virtual public ClapTrap
{
	public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& scav);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& scav);
	
	void guardGate(void);
	void attack(const std::string& target);
};


#endif
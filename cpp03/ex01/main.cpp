/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:50:06 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/19 11:50:06 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap ScavTrapA("Strong");
	ScavTrap ScavTrapB("Weak");
	ScavTrapA.attack("ScavTrapB");
	
	ScavTrapB.attack("ScavTrapA");
	ScavTrapB.guardGate();
}
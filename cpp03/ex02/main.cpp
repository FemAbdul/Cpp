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
#include "FragTrap.hpp"

int main(void)
{
	FragTrap FragTrapA("Strong");
	FragTrap FragTrapB("Weak");
	FragTrapA.attack("FragTrapB");
	
	FragTrapB.attack("FragTrapA");
	FragTrapB.highFivesGuys();
}
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

int main(void)
{
	ClapTrap A;
	ClapTrap B("Weak");

	A.attack("Weak");
	B.takeDamage(10);

	B.beRepaired(5);
	A.attack("Weak");
	return 0;
}
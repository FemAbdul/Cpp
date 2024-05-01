/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:09:28 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/07 08:09:28 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main()
{
	std::string name;

	std::cout<<"Stack Zombie: Enter Zombie Name:";
	std::cin>>name;
	Zombie obj1(name);
	obj1.announce();
	
	randomChump("randfunc");
	
	std::cout<<"Heap Zombie: Enter Zombie Name:";
	std::cin>>name;
	Zombie *bh = newZombie(name);
	bh->announce();
	delete(bh);	

}
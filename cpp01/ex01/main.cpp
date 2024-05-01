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

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int n;
	std::string name;
	std::cout<<"Enter number of Zombies:";
	std::cin>>n;
	if (n <= 0)
	{
		std::cout<<std::endl<<"Invalid Number of Zombies!!!"<<std::endl;
		return (0);
	}
	std::cout<<std::endl<<"Enter Name of Zombie:";
	std::cin>>name;
	std::cout<<std::endl;
	
	Zombie *zombies = zombieHorde(n, name);
	for (int i=0; i < n; i++)
	{
		zombies[i].announce();
	}

	delete[] zombies;	// instead of delete..to delete an array of objects
}
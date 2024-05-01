/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:48:24 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/08 08:48:24 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zomby;
	zomby = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		zomby[i].set_name(name);
	}
	return (zomby);
}

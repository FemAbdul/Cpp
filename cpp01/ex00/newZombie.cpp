/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 07:48:00 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/07 07:48:00 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include<iostream>

Zombie* newZombie(std::string name)
{
	Zombie *ptr;
	ptr = new Zombie(name);
	return (ptr);
}

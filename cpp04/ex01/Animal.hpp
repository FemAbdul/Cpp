/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:06:07 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/23 08:06:07 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <string>

class Animal
{
	protected:
	std::string type;

	public:
	Animal();
	Animal(const Animal &copy);
	Animal& operator=(const Animal &copy);
	virtual ~Animal();

	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif
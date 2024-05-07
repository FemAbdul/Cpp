/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:06:52 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/23 08:06:52 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog:public Animal
{
	private:
	Brain *brain;

	public:
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& copy);
	virtual ~Dog();
	void makeSound(void) const;
};


#endif
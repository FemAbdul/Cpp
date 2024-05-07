/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:10:55 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/24 01:10:55 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	const int numAnimals = 10;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->makeSound();
    }

     for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    Dog b;
    Dog tmp = b;
    tmp.makeSound();

	return 0;
}
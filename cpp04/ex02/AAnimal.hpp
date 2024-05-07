/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:06:07 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/23 08:06:07 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include "Brain.hpp"
#include <string>

class AAnimal
{
	protected:
	std::string type;

	public:
	AAnimal();
	AAnimal(const AAnimal &copy);
	AAnimal& operator=(const AAnimal &copy);
	virtual ~AAnimal();

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:56:28 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/24 19:56:28 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
	std::string type;

	public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal& operator=(const WrongAnimal &copy);
	~WrongAnimal();

	void makeSound(void) const;
	std::string getType(void) const;
};

#endif
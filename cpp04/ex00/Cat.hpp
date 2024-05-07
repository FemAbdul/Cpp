/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:07:07 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/23 08:07:07 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat:public Animal
{
	public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& copy);
	~Cat();
	void makeSound(void) const;
};


#endif
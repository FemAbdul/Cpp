/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:00:47 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/24 20:00:47 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat:public WrongAnimal
{
	public:
	WrongCat();
	WrongCat(const WrongCat& copy);
	WrongCat& operator=(const WrongCat& copy);
	~WrongCat();
	void makeSound(void) const;
};


#endif
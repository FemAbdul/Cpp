/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:39:44 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/20 15:39:44 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdint.h>

#include "Data.hpp"
class Serialize
{
	private:
	Serialize();
	Serialize(Serialize& copy);
	Serialize& operator=(Serialize& copy);
	~Serialize();

	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};



#endif
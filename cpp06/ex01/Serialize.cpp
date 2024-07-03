/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:52:02 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/20 15:52:02 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize()
{}

Serialize::Serialize(Serialize& copy)
{
	(void)copy;
}

Serialize& Serialize::operator=(Serialize& copy)
{
	(void)copy;
	return *this;
}

Serialize::~Serialize()
{}

uintptr_t Serialize::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*> (raw));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:44:45 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/20 20:44:45 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include "Data.hpp"

int main()
{
	Data *d = new Data;
	uintptr_t ptr;
	d->num = 10;

	std::cout<<"Value of d before serializing: "<<d<<std::endl;
	ptr = Serialize::serialize(d);	
	std::cout<<"Value of serialized ptr: "<<&ptr<<std::endl;
	Data *res = Serialize::deserialize(ptr);
	std::cout<<"Value of deserialized res pointer: "<<res<<std::endl;
	std::cout<<"Value held by res: "<<res->num<<std::endl;
	delete d;
}
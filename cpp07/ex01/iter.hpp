/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:06:25 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/24 14:06:25 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *arr, size_t arr_size, void (*f)(T &))
{
	if (arr == NULL || f == NULL)
		return ;
	for (size_t i = 0; i < arr_size; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void print (T &arr)
{
	std::cout<<arr<<std::endl;
}

template <typename T>
void incr(T &element)
{
	element += 1;
}


#endif
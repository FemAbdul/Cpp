/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:02:00 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/07/03 15:02:00 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"


template <typename T>
Array<T>::Array():n(0), arr(new T[0])
{
	std::cout<<"Empty constructor called"<<std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n): n(n), arr(new T[n])
{
	for (unsigned int i = 0; i < n; i++)
		arr[i] = 0;
	std::cout<<"Array created"<<std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
	std::cout<<"Array Destroyed"<<std::endl;
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	this->n = copy.size();
	this->arr = (new T[this->n]);
	for (unsigned int i = 0; i < n; i++)
		this->arr[i] = copy.arr[i];
	std::cout<<"Array Copied"<<std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		delete[] arr;
		this->arr = new T[copy.size()];
		this->n = copy.size();
		for (int i = 0; i < n; i++)
			this->arr[i] = copy.arr[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index  >= n)
		throw std::out_of_range("Index out of range");
	return arr[index];
}

template <typename T>
unsigned int Array<T>::size(void)const
{
	return n;
}


#endif
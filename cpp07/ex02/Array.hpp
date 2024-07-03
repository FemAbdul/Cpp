/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:25:17 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/07/02 08:25:17 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
	unsigned int n;
	T *arr;

	public:
	Array();
	Array(unsigned int n);
	Array(const Array& copy);
	~Array();

	Array& operator=(const Array& copy);
	T& operator[](unsigned int index);

	unsigned int size(void)const;

};
#endif
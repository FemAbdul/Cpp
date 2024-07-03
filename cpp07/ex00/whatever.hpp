/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:14:18 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/22 10:14:18 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T &a, T &b)
{
	return (a < b? a : b);
}

template <typename T>
T max(T &a, T &b)
{
	return (a > b? a : b);
}

#endif
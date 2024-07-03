/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:05:39 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/06/24 14:05:39 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int arr[6] = {2,3,4,5,1,6};
	
	std::cout<<"Before incrementing"<<std::endl;
	iter(arr, 6, print);
	iter(arr, 6, incr);
	std::cout<<"After incrementing"<<std::endl;
	iter(arr, 6, print);

	char c[5] = {'a','b', 'c','d', 'e'};
	std::cout<<"Before incrementing"<<std::endl;
	iter(c, 5, print);
	iter(c, 5, incr);
	std::cout<<"After incrementing"<<std::endl;
	iter(c, 5, print);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:29:30 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/07/02 15:29:30 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
int main()
{
	std::vector<int> myvector;
	myvector.push_back(5);
	myvector.push_back(15);
	myvector.push_back(25);
	myvector.push_back(35);
	try
	{		
		std::vector<int>::iterator it = easyfind(myvector, 25);
		std::cout<<"Element "<<*it<<" found!!"<<std::endl;
		it = easyfind(myvector, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() <<std::endl;
	}
	std::list<int> ls;
	for (int i = 0; i < 10; i++)
		ls.push_back(i);
	try
	{
		std::list<int>::iterator l = easyfind(ls, 8);
		std::cout<<"Element "<<*l<<" found!!"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:53:59 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/08/31 11:53:59 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **argv)
{
	if (ac < 2)
	{
		std::cout<<"Error : Usage: ./Pmerge <numbers>"<<std::endl;
		return (1);
	}
	PmergeMe pm;
	if (pm.check_input(ac, argv))
	{
		std::cout<<"Error: Invalid input."<<std::endl;
		return (1);
	}
	pm.sort();


}

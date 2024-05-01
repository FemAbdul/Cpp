/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:48:13 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/11 15:48:13 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int correct_input(std::string input)
{
	if (input.empty() && input != "DEBUG" && input != "INFO"
	&& input != "WARNING" && input != "ERROR")
		return (0);
	return (1);
}
int main(void)
{
	Harl harl;
	std::string input;

	while (1)
	{
		std::cout<<"Enter a level for Harl: ";
		std::cin>>input;	
		if (!correct_input(input))
			continue;
		harl.complain(input);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:43:46 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/12 00:43:46 by fabdul-k         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	if (argc != 2 || !correct_input(argv[1]))
	{
		std::cout<<"Incorrect arguments!";
		std::cout<<"";
		return (1);
	}
	Harl harl;
	harl.complain(argv[1]);
}
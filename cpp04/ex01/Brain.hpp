/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:44:42 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/24 20:44:42 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
	std::string ideas[100];

	public:
	Brain(void);
	Brain(const Brain& copy);
	Brain& operator=(const Brain& copy);
	~Brain(void);
};


#endif
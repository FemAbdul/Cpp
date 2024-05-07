/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:03:23 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/22 07:03:23 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include "ClapTrap.hpp"

class FragTrap:public ClapTrap
{
	public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap& scav);
	~FragTrap();
	FragTrap& operator=(const FragTrap& scav);
	
	void highFivesGuys(void);
	void attack(const std::string& target);
};


#endif
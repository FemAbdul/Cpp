/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:45:23 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/07/09 10:45:23 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
	MutantStack(): std::stack<T>(){}
	~MutantStack(){}
	MutantStack(const MutantStack &copy):std::stack<T>(copy){}
	MutantStack& operator=(const MutantStack &copy)
	{
		std::stack<T>::operator=(copy);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};



#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:10:21 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/08/30 10:10:21 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <climits>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <iomanip>

class PmergeMe
{
	private:
	std::vector<int> vec;
	std::list<int> lst;

	public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe& operator=(const PmergeMe &copy);

	int	check_input(int size, char **argv);
	void sort();
	void sort_vec(void);
	void sort_list(void);

	template <typename Container>
	void print(Container& con);

	template <typename Container>
	int binarysearch(Container&, int target);
};

#endif
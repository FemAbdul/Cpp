/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:10:41 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/08/30 10:10:41 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this->vec = copy.vec;
		this->lst = copy.lst;	
	}
	return *this;
}

int	PmergeMe::check_input(int size, char **argv)
{
	int i = 1;
	int num;

	while (i < size)
	{
		std::istringstream str(argv[i]);
		std::string rem;
		if (!(str >> num) || (str >> rem))
			return (1);
		if (num < 0 || num > INT_MAX || num < INT_MIN)
			return (1);
		vec.push_back(num);
		lst.push_back(num);
		i++;
	}
	return 0;
}

void PmergeMe::sort(void)
{
	std::cout<<"Before:	";
	print(vec);
	
	clock_t start = clock();
	sort_vec();
	clock_t end = clock();

	std::cout<<"After:	";
	print(vec);
	
	double time_elapsed = (static_cast<double> (end - start) / CLOCKS_PER_SEC) * 1000000;
	std::cout << std::fixed << std::setprecision(6);
	std::cout<<"Time to process a range of "<<vec.size()<<" elements with std::vector : "<<time_elapsed<<" us"<<std::endl;

	start = clock();
	sort_list();
	end = clock();
	time_elapsed = (static_cast<double> (end - start) / CLOCKS_PER_SEC) * 1000000;
	std::cout<<"Time to process a range of "<<vec.size()<<" elements with std::list : "<<time_elapsed<<" us"<<std::endl;
}

void PmergeMe::sort_vec(void)
{
	bool odd_num = vec.size() % 2 != 0;
	std::vector<int>::iterator end = odd_num? vec.end() - 1: vec.end();

	  for (std::vector<int>::iterator itr = vec.begin(); itr != end; itr += 2)
	  {
        if (*itr > *(itr + 1))
            std::swap(*itr, *(itr + 1));
        for (std::vector<int>::iterator next = itr; next != end; next += 2)
		{
            if (*itr > *next)
			{
                std::swap(*itr, *next);
                std::swap(*(itr + 1), *(next + 1));
            }
        }
    }

	std::vector<int> main;
	std::vector<int> pend;
	for (std::vector<int>::iterator it = vec.begin(); it != end; it += 2)
	{
		main.push_back(*it);
		pend.push_back(*(it + 1));
	}
	if (odd_num)
		pend.push_back(vec.back());

	for(std::vector<int>::iterator it = pend.begin(); it != pend.end(); it++)
	{
		int index = binarysearch(main, *it);
		main.insert(main.begin() +index, *it);
	}
	vec.clear();
	vec = main;
}

void PmergeMe::sort_list(void)
{
	bool odd_num = lst.size() % 2 != 0;
	std::list<int>::iterator end = odd_num? --lst.end(): lst.end();
	//here we arrange the list so that in each pair (smaller,larger)
	for (std::list<int>::iterator itr = lst.begin(); itr != end; std::advance(itr,2))
	{
		std::list<int>::iterator itrpair = itr;
		itrpair++;
        if (*itr > *(itrpair))
            std::swap(*itr, *(itrpair));
	}

	for (std::list<int>::iterator itr = lst.begin(); itr != end; std::advance(itr,2))
	{
		for (std::list<int>::iterator next = itr; next != end; std::advance(next,2))
		{
            if (*itr > *next)
                std::swap(*itr, *next);
		}
    }
    
	std::list<int> main;
	std::list<int> pend;
	for (std::list<int>::iterator itr = lst.begin(); itr != end; itr++)
	{
		main.push_back(*itr);
		pend.push_back(*(++itr));
	}

	if (odd_num)
		pend.push_back(lst.back());

	for(std::list<int>::iterator it = pend.begin(); it != pend.end(); it++)
	{
		int index = binarysearch(main, *it);
		std::list<int>::iterator main_it = main.begin();
		std::advance(main_it, index);
		main.insert(main_it, *it);
	}
	lst.clear();
	lst = main;
}

template <typename Container>
int PmergeMe::binarysearch(Container& main, int target)
{
	int high,low,mid;
	
	low = 0;
	high = main.size() - 1;
	
	while (low <= high)
	{
		mid = low + (high - low) / 2;

		typename Container::iterator it = main.begin();
		std::advance(it, mid);
		if (target == *it)
			return mid;
		else if (target < *it)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}

template <typename Container>
void PmergeMe::print(Container& cont)
{
	typename Container::iterator it = cont.begin();
	while (it != cont.end())
	{
		std::cout<<" "<<*it;
		it++;
	}
	std::cout<<std::endl;
}

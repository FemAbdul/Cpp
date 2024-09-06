/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:50:25 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/07/06 17:50:25 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span(unsigned int N): N(N){}

Span::~Span()
{}

Span::Span(const Span &copy):N(copy.N), numbers(copy.numbers){}

Span& Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		N = copy.N;
		numbers = copy.numbers;
	}
	return (*this);
}

void Span::addNumber(int value)
{
	if (numbers.size() >= N)
		throw MaximumElementsException();
	numbers.push_back(value);
}

int Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("Cannot find span as less than 2 numbers stored.");
	std::vector<int> temp = numbers;
	std::sort(temp.begin(), temp.end());
	int shortest_span = temp.at(1) - temp.at(0);
	return (shortest_span);
}

int Span::longestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("Cannot find span as less than 2 numbers stored.");
	std::vector<int> temp = numbers;
	std::sort(temp.begin(), temp.end());
	int max_index = numbers.size() - 1;
	int longest_span = numbers.at(max_index) - numbers.at(max_index - 1);
	return (longest_span);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:50:33 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/07/06 17:50:33 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
class Span
{
	private:
	unsigned int N;
	std::vector<int> numbers;
	Span();

	public:
	Span(unsigned int N);
	Span(const Span &copy);
	~Span();
	Span& operator=(const Span &copy);
	void addNumber(int value);
	int shortestSpan();
	int longestSpan();


	class MaximumElementsException: public std::exception
	{
		virtual const char* what()const throw()
		{
			return "Maximum No. of elements Present!";
		}
	};
	template <typename T>
	void fill_inrange(T begin, T end)
	{
		std::copy(begin, end, std::back_inserter(numbers));
	}
	
};

#endif
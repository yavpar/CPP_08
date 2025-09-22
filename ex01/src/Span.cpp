/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:12:50 by yparthen          #+#    #+#             */
/*   Updated: 2025/06/13 19:32:40 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(int N) : _max_size(N)
{
	if (N < 0)
		throw Span::SpanNegatifN();
	if (static_cast<unsigned long>(N) > static_cast<unsigned long>(UINT_MAX))
		throw Span::SpanOverflow();

	this->v.reserve(N);
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (this->v.size() >= this->_max_size)
		throw Span::SpanFull();

	this->v.push_back(number);
}

int Span::shortestSpan()
{
	if (v.size() < 2)
		throw std::runtime_error("Not enough number to find in the vector");
	
	int shortest = INT_MAX;
	int temp;
	std::vector<int> vt = v;

	std::sort(vt.begin(), vt.end());

	for (std::size_t i = 0; i < v.size() - 1; i++)
	{
		temp = abs(vt[i + 1] - vt[i]);
		if (temp < shortest)
			shortest = temp;
	}
	return shortest;
}

int Span::largestSpan()
{
	if (v.size() < 2)
		throw std::runtime_error("Not enough number to find in the vector");
	
	int largest = INT_MIN;

	std::vector<int> vt = v;
	std::sort(vt.begin(), vt.end());

	std::vector<int>::const_iterator min = std::min_element(vt.begin(), vt.end());
	std::vector<int>::const_iterator max = std::max_element(vt.begin(), vt.end());

	largest = abs(*max - *min);

	return largest;
}

void Span::fillSpan()
{
	v.clear();
	std::vector<int> pool;
	
	for (std::size_t i = 0; i < this->_max_size * 10; i++)
	{
		if (i > 2 && (i % 3 == 0))
			pool.push_back(-i);
		else
			pool.push_back(i);
	}

	std::srand(std::time(NULL));
	std::random_shuffle(pool.begin(), pool.end());

	for (std::size_t i = 0; i < this->_max_size; i++)
		addNumber(pool[i]);
}

void Span::printSpan() const
{
	std::cout << BLUE << "\n\nElements in vector:\n" << NEUTRAL;
	for (std::size_t i = 0; i < v.size(); i++)
		std::cout << MAGENTA << v[i] << '\n';
	std::cout << '\n' << NEUTRAL;
}

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

Span::Span() : _v(0), _capacity(0) {}

Span::Span(const Span & copy) : _v(0), _capacity(copy._capacity) {*this = copy;}

Span::Span(int N) : _capacity(N)
{
	if (N < 0)
		throw Span::SpanNegatifN();
	if (static_cast<unsigned long>(N) > static_cast<unsigned long>(UINT_MAX))
		throw Span::SpanOverflow();
}

Span::~Span() {}

Span Span::operator=(const Span & copy)
{
    if (this != &copy)
    {
        this->_v = copy._v;
        this->_capacity = copy._capacity;
    }

    return (*this);
}

void Span::addNumber(int number)
{
    if (this->_capacity == 0)
        throw Span::SpanEmpty();

	if (this->_v.size() >= this->_capacity)
		throw Span::SpanFull();

	this->_v.push_back(number);
}

int Span::shortestSpan()
{
	if (this->_v.size() < 2)
		throw Span::SpanEmpty();
	
	int shortest = INT_MAX;
	int temp;
	std::vector<int> vt = this->_v;

	std::sort(vt.begin(), vt.end());

	for (std::size_t i = 0; i < this->_v.size() - 1; i++)
	{
		temp = abs(vt[i + 1] - vt[i]);
		if (temp < shortest)
			shortest = temp;
	}
	return shortest;
}

int Span::largestSpan()
{
	if (this->_v.size() < 2)
		throw Span::SpanEmpty();
	
	std::vector<int> vt = this->_v;
	std::sort(vt.begin(), vt.end());

	std::vector<int>::const_iterator min = std::min_element(vt.begin(), vt.end());
	std::vector<int>::const_iterator max = std::max_element(vt.begin(), vt.end());

	int largest = abs(*max - *min);

	return largest;
}

void Span::printSpan() const
{
	std::cout << BLUE << "\nElements in vector:\n" << NEUTRAL;
	for (std::size_t i = 0; i < this->_v.size(); i++)
		std::cout << MAGENTA << this->_v[i] << '\n';
	std::cout << '\n' << NEUTRAL;
}


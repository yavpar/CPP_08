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

Span::Span(unsigned int N) : _maxSize(N)
{
	this->v.reserve(N);
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (this->v.size() >= this->_maxSize)
		throw Span::SpanFull();

	this->v.push_back(number);
}

int Span::shortestSpan()
{
}

int Span::largestSpan()
{
}

void Span::fillSpan()
{
}

void Span::fillSpan(int min, int max)
{
}


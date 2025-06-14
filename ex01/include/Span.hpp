/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:38:30 by yparthen          #+#    #+#             */
/*   Updated: 2025/06/13 19:32:40 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <limits>
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Span
{
	public:
		Span(unsigned int = 10);
		~Span();
		void addNumber(int number);
		int shortestSpan();
		int largestSpan();
		void fillSpan();
		void fillSpan(int min, int max);

	class SpanFull : std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Span is full, can't add more numbers";
			}
	};

	private:
		unsigned int _max_size;
		std::vector<int> v;
};

#endif

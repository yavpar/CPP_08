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
#include <climits>
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define MARRON "\033[1;33m"
# define GREEN "\033[1;32m"
# define MAGENTA "\033[1;35m"
# define NEUTRAL "\033[0m"

class Span
{
	public:
		Span(int = 1);
		~Span();
		void addNumber(int number);
		int shortestSpan();
		int largestSpan();
		void fillSpan();
		void printSpan() const;

		template <typename iter>
		void addNumber(iter first, iter last)
		{
			while (first != last)
			{
				if (v.size() >= _max_size)
					throw Span::SpanFull();
				v.push_back(*first);
				++first;
			}
		}
	
	class SpanFull : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Span is full, can't add more numbers";
			}
	};
	class SpanNegatifN : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return "Enter a negative number";
		}
	};
	class SpanOverflow : public std::exception 
	{
		public :
			virtual const char *what() const throw()
			{
				return "Stack Overflow";
			}
	};

	private:
		unsigned int _max_size;
		std::vector<int> v;
};

#endif

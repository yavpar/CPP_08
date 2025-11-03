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

#include <algorithm>
#include <vector>
#include <exception>
#include <climits>
#include <iterator>
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
		Span();
        Span(const Span & copy);
		Span(int N);
		~Span();
        Span operator=(const Span & copy);
		void addNumber(int number);
		int shortestSpan();
		int largestSpan();
		void printSpan() const;

        template<typename A>
        void AddMulti(A itF, A itL)
        {
            std::size_t k = distance(itF, itL);

            std::cout << "k = " << k << " y v.size " << this->_v.size() << '\n';
            if (k + this->_v.size() > this->_capacity)
                throw Span::SpanFull();

            std::vector<int> t;

            std::srand(static_cast<unsigned int>(std::time(NULL)));

            std::generate(t.begin(), t.end(), std::rand);

            std::sort(t.begin(), t.end());
            t.erase(std::unique(t.begin(), t.end()), t.end());

            while (t.size() < k)
            {
                int number = std::rand();
                if (std::find(t.begin(), t.end(), number) == t.end())
                    t.push_back(number);
            }

            std::random_shuffle(t.begin(), t.end());

            this->_v.insert(this->_v.end(), t.begin(), t.end());
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

        class SpanEmpty : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Span is empty";
                }
        };

        private:
            std::vector<int> _v;
            unsigned int _capacity;
};

#endif

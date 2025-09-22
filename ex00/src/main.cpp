/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:29:03 by yparthen          #+#    #+#             */
/*   Updated: 2025/06/13 18:40:44 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void test_vector(void)
{
	std::cout << "--- TESTING VECTOR CONTAINER ---\n\n";
	std::vector<int> v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);

	int find = 2;
	std::cout << "Vector has 3 elements: {0, 1, 2}\n";
	std::cout << "Number to find: " << find << '\n';
	try
	{
		std::vector<int>::const_iterator it = easyfind(v, find);
		std::cout << "Found in vector: " << *it << '\n';
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << ": " << find << '\n';
	}

}

void test_list(void)
{
	std::cout << "--- TESTING LIST CONTAINER ---\n\n";

	std::list<int> l;
	l.push_back(0);
	l.push_back(1);
	l.push_back(2);

	int find = 8;
	std::cout << "List has 3 elements: {0, 1, 2}\n";
	std::cout << "Number to find: " << find << '\n';

	try
	{
		std::list<int>::const_iterator it = easyfind(l, find);
		std::cout << "Found in list: " << *it << '\n';
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << ": " << find << '\n';
	}
}

void test_deque(void)
{
	std::cout << "--- TESTING DEQUE CONTAINER ---\n\n";

	std::deque<int> d;
	d.push_back(0);
	d.push_back(1);
	d.push_back(2);

	int find = 2;
	std::cout << "Deque has 3 elements: {0, 1, 2}\n";
	std::cout << "Number to find: " << find << '\n';

	try
	{
		std::deque<int>::const_iterator it = easyfind(d, find);
		std::cout << "Found in deque: " << *it << '\n';
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << ": " << find << '\n';
	}
}

void test_set(void)
{
	std::cout << "--- TESTING SET CONTAINER ---\n\n";

	std::set<int> s;
	s.insert(0);
	s.insert(1);
	s.insert(2);

	int find = 2;
	std::cout << "Set has 3 elements: {0, 1, 2}\n";
	std::cout << "Number to find: " << find << '\n';

	try
	{
		std::set<int>::const_iterator it = easyfind(s, find);
		std::cout << "Found in set: " << *it << '\n';
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << ": " << find << '\n';
	}
}

int main(void)
{
	test_vector();
	std::cout << std::endl;
	test_list();
	std::cout << std::endl;
	test_deque();
	std::cout << std::endl;
	test_set();
}

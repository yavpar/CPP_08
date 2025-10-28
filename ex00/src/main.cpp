#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>

#include "easyfind.hpp"
#include "Except.hpp"

#define N 5 

void testContainer(std::string name)
{
	std::cout << MARRON << "\n--- Testing: " << RED << name << " ---\n" << NEUTRAL;
}

template <typename A>
void showType(A & a,const std::string & name)
{
	testContainer(name);

	for (std::size_t i = 0; i < N; i++)
		a.push_back(i * 2 - (i * 4 / 2 == 0));

	typename A::const_iterator it_b = a.begin();
	typename A::const_iterator it_e = a.end();

	std::cout << name << ":\n";
	for (; it_b != it_e; it_b++)
		std::cout << "<" << *it_b << ">\n";

}

template <typename B>
void test(B const & b, int ffind)
{
	try 
	{ 
		typename B::const_iterator found = easyfind(b, ffind); 
		std::cout << "Value found = " << GREEN << *found << '\n' << NEUTRAL; 
	}
	catch (std::exception & e)
		{ std::cerr << RED << "Oops: " << e.what() << '\n' << NEUTRAL;}

}

int getValue(void)
{
	int num;
	std::cin >> num;

	if (std::cin.fail())
	{
		std::cerr << RED << "Invalid entry. By default: 42\n" << NEUTRAL;
		return (42);
	}
	return num;
}

void showTypes(std::set<int> s)
{
	testContainer("Set");
	s.insert(3);
	s.insert(6);
	s.insert(42);
	s.insert(9);
	s.insert(78);

	std::set<int>::const_iterator it_b = s.begin();
	std::set<int>::const_iterator it_e = s.end();

	std::cout << "Set:\n";
	for (; it_b != it_e; it_b++)
		std::cout << "<" << *it_b << ">\n";
}

int main(void)
{
	std::vector<int> v;
	std::list<int> l;
	std::set<int> s;
	std::deque<int> d;

	showType(v, "Vector");
	showType(l, "List");
	showType(d, "Deque");
	showTypes(s);

	int ffind = getValue();
	
	test(v, ffind);
	test(l, ffind);
	test(d, ffind);
	test(s, ffind);

	return 0;
}


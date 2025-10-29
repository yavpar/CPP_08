#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <cstdlib>
#include "easyfind.hpp"
#include "Except.hpp"

#define N 5 

void testContainer(std::string name)
{
	std::cout << MARRON << "\n--- Testing: " << name << " ---\n" << NEUTRAL;
}

template <typename A>
void showType(A & a,const std::string & name)
{
	testContainer(name);
     int ran;

	for (std::size_t i = 0; i < N; i++)
   { 
        //ran = std::rand() % 1000;
        ran = arc4random() % 1000;
        if (ran % 2 == 0)
		    a.push_back(i * ran);
        else
		    a.push_back(i * -ran);
    }
	typename A::const_iterator it_b = a.begin();
	typename A::const_iterator it_e = a.end();

	std::cout << BLUE << name << NEUTRAL << ":\n";
	for (; it_b != it_e; it_b++)
		std::cout << GREEN << *it_b << NEUTRAL << "\n";

}

template <typename B>
void test(B const & b, int ffind)
{
	try 
	{ 
		typename B::const_iterator found = easyfind(b, ffind); 
		std::cout << GREEN << "Value found = " << *found << '\n' << NEUTRAL; 
	}
	catch (std::exception & e)
		{ std::cerr << RED << "Oops! " << e.what() << '\n' << NEUTRAL;}

}

int getValue(void)
{
	int num;
    std::cout << MARRON << "\nPlease enter a number to find:\n" << NEUTRAL;
	std::cin >> num;

	if (std::cin.fail())
	{
		std::cerr << MARRON << "Invalid entry.\nBy default: 42\n" << NEUTRAL;
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

	std::set<int>::const_iterator it_b = s.begin();
	std::set<int>::const_iterator it_e = s.end();

	std::cout << BLUE << "Set:\n" << NEUTRAL;
	for (; it_b != it_e; it_b++)
		std::cout << GREEN << *it_b << "\n";
    std::cout << NEUTRAL;
}

int main(void)
{
    std::srand(std::time(0));

	std::vector<int> v;
	std::list<int> l;
	std::set<int> s;
	std::deque<int> d;

	showType(v, "Vector");
	showType(l, "List");
	showType(d, "Deque");
	showTypes(s);

	int ffind = getValue();

    std::cout << BLUE << "In Vector:\t" << NEUTRAL;
	test(v, ffind);
    std::cout << BLUE << "In List:\t" << NEUTRAL;
	test(l, ffind);
    std::cout << BLUE << "In Deque:\t" << NEUTRAL;
	test(d, ffind);
    std::cout << BLUE << "In Set:\t" << NEUTRAL;
	test(s, ffind);

	return 0;
}


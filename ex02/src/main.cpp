#include "MutantStack.hpp"
#include <iostream>
#include <list>
# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define MARRON "\033[1;33m"
# define GREEN "\033[1;32m"
# define MAGENTA "\033[1;35m"
# define NEUTRAL "\033[0m"
#define MAX_ELEM 10

void test_main()
{
    MutantStack<int> mStack;
    mStack.push(0);
    mStack.push(1);
    std::cout << "first element: " << mStack.top() << std::endl;
    mStack.pop();
    std::cout << "pop() realice.\nsize: " << mStack.size() << std::endl;
    mStack.push(2); mStack.push(3); mStack.push(4); //[...] mStack.push(0);
    MutantStack<int>::iterator it = mStack.begin(); MutantStack<int>::iterator ite = mStack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
    ++it; }
    std::stack<int> s(mStack);
}

void test_list()
{
    std::list<int> mStack;
    mStack.push_back(0);
    mStack.push_back(1);
    std::cout << "first element: " << mStack.back() << std::endl;
    mStack.pop_back();
    std::cout << "pop_back() done!.\nsize: " << mStack.size() << std::endl;
    mStack.push_back(2); mStack.push_back(3); mStack.push_back(4); //[...] mStack.push(0);
    std::list<int>::iterator it = mStack.begin(); std::list<int>::iterator ite = mStack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
    ++it; }
    std::stack<int, std::list<int> > s(mStack); 
}

int main()
{
	std::cout << MAGENTA << "\n\t====== Tests with iterators ======" << NEUTRAL << '\n';

    MutantStack<int> mStack;
    for (int i = 0; i < MAX_ELEM; ++i)
        mStack.push(i * 10);

    std::cout << MARRON << "\n=== with const_iterator ===" << NEUTRAL << '\n';;
    MutantStack<int>::const_iterator it = mStack.begin();
	std::cout << GREEN;
    for (; it != mStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << NEUTRAL << '\n'; 

    std::cout << MARRON << "\n=== with const_reverse_iterator ===" << NEUTRAL << '\n';;
	std::cout << GREEN;
	MutantStack<int>::const_reverse_iterator revIt = mStack.rbegin();
	for ( ; revIt != mStack.rend(); ++revIt)
		std::cout << *revIt << " ";
    std::cout << NEUTRAL << '\n'; 


    std::cout << MARRON << "\n=== with Main ===" << NEUTRAL << '\n';
	test_main();

    std::cout << MARRON << "\n=== with List ===" << NEUTRAL << '\n';
	test_list();
    return 0;
}


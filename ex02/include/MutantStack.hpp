#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>


# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"

template <typename T>
class MutantStack : public std::stack<T>
{
    MutantStack();
    MutantStack(const MutantStack & m);
    ~MutantStack();
    MutantStack & operator=(const MutantStack & m);

    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    template <typename T>
    int  easyfind(const T & container, int & val);
}

#endif
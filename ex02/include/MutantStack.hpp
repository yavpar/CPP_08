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
    public:
        MutantStack();
        MutantStack(const MutantStack & m);
        ~MutantStack();
        MutantStack & operator=(const MutantStack & m);

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;

        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;

};

/*
template <typename A>
int  easyfind(const A & container, int & val);
*/
#include "MutantStack.tpp"
#endif

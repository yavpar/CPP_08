#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() 
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack & m)
{
    *this = m;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack & m)
{
    if (this != &m)
        std::stack<T>::operator=(m);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}
    // iterator end()

    // const_iterator begin() const
    // const_iterator end() const

template <typename T>
int  easyfind(const T & container, int & val)
{
	typename T::const_terator it;
	it = find(container.begin(), container.end(), val);

	if (it == container.end())
		throw ValueNotFound();
	
	return (*it);
}

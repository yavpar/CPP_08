#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() 
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack & m) : std::stack<T>(m)
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

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rbegin()
{
    return c.rbegin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rend()
{
    return c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rbegin() const
{
    return c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rend() const
{
    return c.rend();
}

template <typename T>
int  easyfind(const T & container, int & val)
{
	typename T::const_terator it;
	it = find(container.begin(), container.end(), val);

	if (it == container.end())
		throw std::runtime_error("Value Not Found");

	return (*it);
}

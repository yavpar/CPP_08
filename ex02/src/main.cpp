#include "MutantStack.hpp"
#include <iostream>

/*
int main()
{
    MutantStack<int> mstack;
    mstack.push(0);
    mstack.push(1);
    std::cout << "first element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "pop() realice.\nsize: " << mstack.size() << std::endl;
    mstack.push(2); mstack.push(3); mstack.push(4); //[...] mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
    ++it; }
    std::stack<int> s(mstack); return 0;
}*/

// ----------------------------------------------------
// Test 1: iteradores normales (iterator)
// ----------------------------------------------------
void test_iterators()
{
    std::cout << "\n=== Test 1: iterator ===" << std::endl;
    MutantStack<int> mstack;
    for (int i = 0; i < 5; ++i)
        mstack.push(i * 10);

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// ----------------------------------------------------
// Test 2: const_iterator
// ----------------------------------------------------
void test_const_iterators()
{
    std::cout << "\n=== Test 2: const_iterator ===" << std::endl;
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; ++i)
        mstack.push(i * 10);

    const MutantStack<int> const_stack = mstack;

    for (MutantStack<int>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// ----------------------------------------------------
// Test 3: reverse_iterator
// ----------------------------------------------------
void test_reverse_iterators()
{
    std::cout << "\n=== Test 3: reverse_iterator ===" << std::endl;
    MutantStack<int> mstack;
    for (int i = 0; i < 5; ++i)
        mstack.push(i * 10);

    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// ----------------------------------------------------
// Test 4: const_reverse_iterator
// ----------------------------------------------------
void test_const_reverse_iterators()
{
    std::cout << "\n=== Test 4: const_reverse_iterator ===" << std::endl;
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; ++i)
        mstack.push(i * 10);

    const MutantStack<int> const_stack = mstack;

    for (MutantStack<int>::const_reverse_iterator it = const_stack.rbegin(); it != const_stack.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// ----------------------------------------------------
// Test 5: easyfind()
// ----------------------------------------------------
/*
void test_easyfind()
{
    std::cout << "\n=== Test 5: easyfind() ===" << std::endl;
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; ++i)
        mstack.push(i * 3);

    int value = 9;

    try
    {
        int found = easyfind(mstack, value);
        std::cout << "Value " << value << " found: " << found << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    value = 7;
    try
    {
        int found = easyfind(mstack, value);
        std::cout << "Value " << value << " found: " << found << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
*/
// ----------------------------------------------------
// MAIN
// ----------------------------------------------------
int main()
{
    test_iterators();
    test_const_iterators();
    test_reverse_iterators();
    test_const_reverse_iterators();
//    test_easyfind();
    return 0;
}


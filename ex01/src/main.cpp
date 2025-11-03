#include "Span.hpp"


void testAddN(void)
{
     try
     {
        Span s = Span(5);
        std::vector<int> v(5);
       
        s.addNumber(8);
        s.addNumber(9);
        s.addNumber(-89);
        s.addNumber(0);
        s.addNumber(-23);
        s.printSpan();
        std::cout << BLUE << "Largest distance: " << GREEN << s.largestSpan() << NEUTRAL << '\n';
        std::cout << BLUE << "Shorest distance: " << GREEN << s.shortestSpan() << NEUTRAL << '\n';
    }
    catch (const std::exception & e)
    {
        std::cerr << "Exception caught: " << RED << e.what() << NEUTRAL << '\n';
    }

}


void testAddNException(void)
{
     try
     {
        Span s = Span(5);
        std::vector<int> v(5);
       
        s.addNumber(89);
        s.addNumber(8);
        s.addNumber(9);
        s.addNumber(-89);
        s.addNumber(0);
        s.addNumber(-23);
        s.printSpan();
        std::cout << BLUE << "Largest distance: " << GREEN << s.largestSpan() << NEUTRAL << '\n';
        std::cout << BLUE << "Shorest distance: " << GREEN << s.shortestSpan() << NEUTRAL << '\n';
    }
    catch (const std::exception & e)
    {
        std::cerr << "Exception caught: " << RED << e.what() << NEUTRAL << '\n';
    }

}

void testSpanEmpty(void)
{
     try
     {
        Span s = Span(0);
        std::vector<int> v(5);
       
        s.addNumber(89);
        s.addNumber(8);
        s.addNumber(9);
        s.addNumber(-89);
        s.addNumber(0);
        s.addNumber(-23);
        s.printSpan();
        std::cout << BLUE << "Largest distance: " << GREEN << s.largestSpan() << NEUTRAL << '\n';
        std::cout << BLUE << "Shorest distance: " << GREEN << s.shortestSpan() << NEUTRAL << '\n';
    }
    catch (const std::exception & e)
    {
        std::cerr << "Exception caught: " << RED << e.what() << NEUTRAL << '\n';
    }

}

void testAddMulti()
{
    try
    {
        Span s = Span(1000);
        std::vector<int> v(50);
       
        s.AddMulti(v.begin(), v.end());
        s.printSpan();
        std::cout << BLUE << "Largest distance: " << GREEN << s.largestSpan() << NEUTRAL << '\n';
        std::cout << BLUE << "Shorest distance: " << GREEN << s.shortestSpan() << NEUTRAL << '\n';
    }
    catch (const std::exception & e)
    {
        std::cerr << "Exception caught: " << RED << e.what() << NEUTRAL << '\n';
    }
}

int main(void)
{
    std::cout << MARRON << "\n***** Test  AddNumber *****" << NEUTRAL << '\n';
    testAddN();

    std::cout << MARRON <<  "\n**** Test  AddNumber with Exception *****" << NEUTRAL << '\n';
    testAddNException();

    std::cout << MARRON << "\n***** Test  Span Empty *****" << NEUTRAL << '\n';
    testSpanEmpty();

    std::cout << MARRON << "\n***** Test Add Multi *****" << NEUTRAL << '\n';
    testAddMulti();

    std::cout << "\n***** Test with Negative number ******" << NEUTRAL << '\n';
    try
    {
        Span s = Span(-1);
    }
    catch (const std::exception & e)
    {
        std::cerr << RED << "Exception caught: " << e.what() << NEUTRAL << NEUTRAL << '\n';
    }
}

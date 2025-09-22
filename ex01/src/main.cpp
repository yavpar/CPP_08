#include "Span.hpp"

int main(void)
{
    try {
        Span s = Span(3);
        //s.fillSpan();
        // s.addNumber(-9);
        std::vector<int> v;
        
        for (std::size_t i = 0; i < 5; ++i)
            v.push_back(i * 2);

        s.addNumber(v.begin(), v.end());
        s.printSpan();
        std::cout << BLUE << "Largest distance: " << GREEN << s.largestSpan() << NEUTRAL << '\n';
        std::cout << BLUE << "Shorest distance: " << GREEN << s.shortestSpan() << NEUTRAL << '\n';
    }
    catch (const std::exception & e)
    {
        std::cerr << "Exception caught: " << RED << e.what() << NEUTRAL << '\n';
    }
}
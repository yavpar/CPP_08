#include "Span.hpp"

int main(void)
{
    try {
        Span s = Span(1000);
        std::vector<int> v(5);
       
        std::cout << MAGENTA << "Antes de AddMulti" << NEUTRAL << '\n';
        s.AddMulti(v.begin(), v.end());
        std::cout << MAGENTA << "Despues de AddMulti" << NEUTRAL << '\n';
        s.printSpan();
        std::cout << BLUE << "\n\nLargest distance: " << GREEN << s.largestSpan() << NEUTRAL << '\n';
        std::cout << BLUE << "Shorest distance: " << GREEN << s.shortestSpan() << NEUTRAL << '\n';
    }
    catch (const std::exception & e)
    {
        std::cerr << "Exception caught: " << RED << e.what() << NEUTRAL << '\n';
    }
}

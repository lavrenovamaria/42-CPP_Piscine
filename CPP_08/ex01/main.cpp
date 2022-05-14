#include "Span.hpp"
#include <iostream>

#define SIZE 6

int main()
{

	try
	{
		Span sp = Span(6);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

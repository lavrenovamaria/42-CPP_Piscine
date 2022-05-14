#include "Span.hpp"
#include <iostream>

#define SIZE 10

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(1);
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

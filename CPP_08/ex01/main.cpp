#include "Span.hpp"
#include <iostream>

void testFromSubject(){
	std::cout << "---Test from subject---- " << std::endl;
	try{
		Span sp = Span(5);
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
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
}

void testMax(void) {
	std::cout << "------Test min max------ " << std::endl;
	Span sp = Span(10000);

	for (int i = -5000; i <= 4999; i++)
		sp.addNumber(i);
	std::cout << "Shortest span: " << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void testRange(void) {
	std::cout << "-------Test range------- " << std::endl;
	std::vector<int>  v;
	Span sp(9);

	for (int i = 1 ; i < 10 ; i++)
		v.push_back(i * 5);
	sp.addRange(std::begin(v), std::end(v));
	std::cout << "Shortest span: " << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main(){
	testFromSubject();
	testMax();
	testRange();
	return 0;
}

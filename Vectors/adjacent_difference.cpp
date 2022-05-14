#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

int main(){
	srand(time(NULL));
	std::vector<int> inputs(15);
	for(int i = 0; i < 15; i++) inputs[i] = (rand() % 200);
	//std::vector<int> result(15);
	std::cout << "Array contains : ";
	for(int i = 0; i < inputs.size(); i++) std::cout << inputs[i] << " ";
	std::cout << "\n";
	std::vector<int> tmp(inputs);
	std::vector<int>::iterator count = tmp.begin();
	std::sort(std::begin(tmp), std::end(tmp));
	std::cout << "Sort array contains : ";
	for(int i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " ";
	std::cout << "\n";
	std::adjacent_difference(std::begin(tmp), std::end(tmp), std::begin(tmp));
	std::cout << "adjacent array contains : ";
	for(int i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " ";
	std::cout << "\n";
	int min = *std::min_element(std::begin(tmp), std::end(tmp));
	std::cout << "min " << min;
}

	// try
	// {
	// 	srand(time(NULL));
	// 	Span span = Span(15);
	// 	std::vector<int> sp(15);
	// 	for(int i = 0; i < 15; i++) span.addNumber(rand() % 200);
	// 	std::cout << "Array contains : ";
	// 	std::vector<int>::iterator count = sp.begin();
	// 	std::cout << "Исходное содержимое: \n";
	// 	count = sp.begin();
	// 	while(count != sp.end()){
	// 		std::cout << *count << " ";
	// 		count++;
	// 	}
	// 	std::cout << "\n\n";

	// 	std::cout << "Shortest span: " << std::endl;
	// 	std::cout << span.shortestSpan() << std::endl;
	// 	std::cout << "Longest span: " << std::endl;
	// 	std::cout << span.longestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

#include <iostream>
#include "Easyfind.hpp"
#define SIZE 10

int main(){
	std::vector<int> vector;
	std::deque<int> deque;
	std::list<int> list;
	std::vector<int>::iterator p;

	for(int i = 0; i < SIZE; i++){
		vector.push_back(i);
		deque.push_back(i);
		list.push_back(i);
	}

	std::cout << "Содержимое: \n";
	p = vector.begin();
	while(p != vector.end()){
		std::cout << *p << " ";
		p++;
	}
	std::cout << "\n\n";

	std::cout << "[Search deque]" << std::endl;
	try {
		std::deque<int>::iterator iter = easyfind(deque, 3);
		std::cout << "Found value " << 3 << " at index "
			<< std::distance(std::begin(deque), iter) << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "[Search list]" << std::endl;
	try {
		std::list<int>::iterator iter = easyfind(list, 6);
		std::cout << "Found value " << 6 << " at index "
			<< std::distance(std::begin(list), iter) << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "[Search vector]" << std::endl;
	try {
		std::vector<int>::iterator iter = easyfind(vector, 9);
		std::cout << "Found value " << 9 << " at index "
			<< std::distance(std::begin(vector), iter) << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
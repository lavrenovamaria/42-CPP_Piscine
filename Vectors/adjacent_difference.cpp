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
	//std::transform(std::begin(tmp), std::end(tmp), std::begin(tmp), [] (int& i) { return std::abs(i); });
	int min = *std::min_element(std::begin(tmp), std::end(tmp));
	//min = std::abs(*count - *(count - 1));
	std::cout << "min " << min;
	//for(int i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " ";
}

// CPP program to illustrate
// std :: adjacent_difference

#include <iostream> // std::cout
#include <numeric> // std::adjacent_difference

// Driver code
// int main()
// {
// 	int val[] = { 1, 2, 3, 5, 9, 11, 12 };
// 	int n = sizeof(val) / sizeof(val[0]);
// 	int result[7];

// 	// Array contains
// 	std::cout << "Array contains :";
// 	for (int i = 0; i < n; i++)
// 		std::cout << " " << val[i];
// 	std::cout << "\n";

// 	// Using default std :: adjacent_difference
// 	std::adjacent_difference(val, val + 7, result);
// 	std::cout << "Using default adjacent_difference: ";
// 	for (int i = 1; i < n; i++)
// 		std::cout << result[i] << ' ';
// 	std::cout << '\n';

// 	return 0;
// }

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int value){
	typename T::iterator p = std::find(container.begin(), container.end(), value);
	if (p == container.end())
		throw std::exception();
	else
		return (p);
}


#endif
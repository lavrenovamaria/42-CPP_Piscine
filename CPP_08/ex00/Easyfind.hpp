#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <cctype>
#include <list>
#include <array>
#include <deque>
#include <vector>

/*Мы делаем шаблонную функцию easyfind, 
которая будет находить первое вхождение
второго параметра в первом параметре
std::find из библиотеки <algorithm>
В контейнере хранится несколько объектов
какого-либо типа(vector, set, deque)
*/

template <typename T>
typename T::iterator easyfind(T &container, int value){
	typename T::iterator p = std::find(container.begin(), container.end(), value);
	if (p == container.end())
		throw std::exception();
	else
		return (p);
}


#endif
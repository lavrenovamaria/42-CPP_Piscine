#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <algorithm>
#include <stack>

/*
мы реализуем контейнер с функцией итератора,
добавленной в стек
std::stack не выделяют как самостоятельный
контейнер — он есть адаптер для std::vector
В нём не применим итератор
Итератор мы прикрепим к контейнеру std::stack
*создать MutantStack наследованием от std::stack
std::stack предоствит итератор
Также можно подтвердить, что к объекту
container_type std::stack<T> можно получить
доступ с помощью c(лежит в protected)
*/
template <typename T>
class MutantStack : public std::stack <T>{
	public:
		MutantStack(){};
		~MutantStack(){};
		MutantStack(MutantStack const &arg) : std::stack<T>(arg){};
		MutantStack &operator=(MutantStack const &arg){
			*this= arg;
		};
		//наследование от std::stack
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){
			return this->c.begin();
		};
		iterator end(){
			return this->c.end();
		};
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rev_begin(){
			return this->c.rbegin();
		};
		reverse_iterator rev_end(){
			return this->c.rend();
		};
};

#endif

#include "Mutantstack.hpp"
#include <stack>
#include <vector>
#include <iostream>

int main(){
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	//узнаём что самое последнее лежит
	std::cout << mstack.top() << std::endl;//ответ - 17
	mstack.pop();//удалим его
	std::cout << mstack.size() << std::endl;//ответ - 1
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Iterator output:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int>  s(mstack);
	std::cout << std::endl;
	MutantStack<int>::reverse_iterator it2 = mstack.rev_begin();
	MutantStack<int>::reverse_iterator ite2 = mstack.rev_end();
	std::cout << "Reverse iterator output:" << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		it2++;
	}
	std::cout << std::endl;

	MutantStack<char> arr1;
	arr1.push('d');
	arr1.push('o');
	arr1.push('g');
	arr1.push('g');
	arr1.push('o');

	MutantStack<char>::iterator it1 = arr1.begin();
	MutantStack<char>::iterator ite1 = arr1.end();

	std::cout << "Output of doggo:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1  << std::endl;
		++it1;
	}

	return (0);
}

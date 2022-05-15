#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

/*Мы делаем класс для хранения n кол-ва элементов
(unsigned int).
*addNumber функция, которая хранит 1 число
*shortestSpan означает разницу между
минимальным значением внутреннего элемента
и следующим минимальным значением, а
*longestSpan означает разницу между минимальным
значением и максимальным значением
*rangeAddNumber - метол для добавления
диапазона итераторов в вектор
*/

class Span{
	private:
		std::vector<int>_vector;
		unsigned int	_maxElementsValue;
	public:
		Span();
		~Span();
		Span(Span const &arg);
		Span &operator=(Span const &arg);
		Span(unsigned int n);
		void addNumber(int num);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
		class vectorIsFull : public std::exception{
			public :
				virtual const char* what() const throw();
		};
		class vectorIsLessThanTwo : public std::exception{
			public :
				virtual const char* what() const throw();
		};
};

#endif

/*
функция с именем addRange класса
Span должна иметь возможность работать
с любым Container, поэтому ее следует
определить как шаблон функции. В настоящее
время необходимо иметь возможность
получать итератор и указатель, поэтому
трудно решить, как определить имя типа.
*/

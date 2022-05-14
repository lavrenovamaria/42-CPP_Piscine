#include "Span.hpp"

Span::Span(){}
Span::Span(Span const &arg){
	*this= arg;
}

Span &Span::operator=(Span const &arg){
	_vector = arg._vector;
	_maxElementsValue = arg._maxElementsValue;
	return *this;
}

Span::Span(unsigned int n){
	if(n <= 1)
		throw vectorIsLessThanTwo();
	_vector = std::vector<int>();
}

//числа должны быть разные, если уже есть, то бросаем исключение
void Span::addNumber(int num){
	if(_vector.end() - _vector.begin() >= num)
		throw vectorIsFull();
	_vector.push_back(num);
}
//необходимо узнать размер диапазона
void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	if(_vector.size() + std::distance(begin, end) > _maxElementsValue)
		throw vectorIsFull();
	while(begin != end)
		_vector.push_back(*begin++);
}
//std::adjacent_difference, чтобы найти разницу между соседними элементами
int Span::shortestSpan(){
	std::vector<int> tmp(_vector);//сохраняем существующие элементы
	std::sort(std::begin(tmp), std::end(tmp));
	std::adjacent_difference(std::begin(tmp), std::end(tmp), std::begin(tmp));
	std::transform(std::begin(tmp), std::end(tmp), std::begin(tmp), [] ( const int& i) { return std::abs(i); });
	return ((*std::min_element(std::begin(tmp), std::end(tmp))));
}

int Span::longestSpan(){
	std::vector<int> tmp(_vector);
	std::sort(std::begin(tmp), std::end(tmp));
	std::vector<int>::iterator begin = tmp.begin();
	std::vector<int>::iterator end = tmp.end() - 1;
	return *end - *begin;
}

const char *Span::vectorIsFull::what() const throw(){
	return("Vector is full");
}

const char *Span::vectorIsLessThanTwo::what() const throw(){
	return("Vector is less than two elements");
}

Span::~Span(){}

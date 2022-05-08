#include "Converter.hpp"

Converter::Converter(){}
Converter::~Converter(){}
Converter::Converter(Converter const &arg){
	*this = arg;
}

Converter &Converter::operator=(const Converter &arg){
	if(this == &arg)
		return *this;
	return *this;
}

const char *Converter::notDisplayable::what() const throw(){
	return("Not displayable");
}

const char *Converter::impossibleToConvert::what() const throw(){
	return("Impossible to convert");
}

void Converter::setValue(double num){
	this->_num = num;
}

double Converter::getValue()const{
	return this->_num;
}

void Converter::convertToChar()const{
	std::cout << "char: ";
	if (!isascii(static_cast<int>(this->_num)))
		throw Converter::impossibleToConvert();
	if (!isprint(static_cast<int>(this->_num)))
		throw Converter::notDisplayable();

	std::cout << static_cast<char>(this->_num) << std::endl;
}

void Converter::convertToInt()const{
	std::cout << "int: ";

	if (this->_num > std::numeric_limits<int>::max() || \
		this->_num < std::numeric_limits<int>::min() || \
		std::isnan(this->_num) || std::isinf(this->_num))
		throw Converter::impossibleToConvert();

	std::cout << static_cast<int>(this->_num) << std::endl;
}

void convertToFloat()const;
void convertToDouble()const;

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
	_num = num;
}

double Converter::getValue()const{
	return _num;
}

void Converter::convertToChar()const{
	std::cout << "char: ";
	if (!isascii(static_cast<int>(_num)))
		throw Converter::impossibleToConvert();
	if (!isprint(static_cast<int>(_num)))
		throw Converter::notDisplayable();

	std::cout << static_cast<char>(_num) << std::endl;
}
//static_cast(expression) static_cast<>()
//используется для приведения типов целых
//чисел. 'например.' char->long, int->short и т. д.

void Converter::convertToInt()const{
	std::cout << "int: ";

	if (_num > std::numeric_limits<int>::max() || \
		_num < std::numeric_limits<int>::min() || \
		std::isnan(_num) || std::isinf(_num))
		throw Converter::impossibleToConvert();

	std::cout << static_cast<int>(_num) << std::endl;
}
//Может ли целевой тип соответствовать исходному типу проверяется через
//std::numeric_limits<>::max()
void Converter::convertToFloat()const{
	std::cout << "float: ";
	if (std::isnan(static_cast<float>(this->_num)))
		std::cout << "nanf" << std::endl;
	else if (_num > std::numeric_limits<float>::max())
		std::cout << "inff" << std::endl;
	else if (_num < std::numeric_limits<float>::min())
		std::cout << "-inff" << std::endl;
	else
		std::cout << static_cast<float>(_num) << "f" << std::endl;
}

void Converter::convertToDouble()const{
		std::cout << "double: ";
	if (std::isnan(_num))
		std::cout << "nan" << std::endl;
	else if (_num == std::numeric_limits<double>::infinity())
		std::cout << "inf" << std::endl;
	else if (_num == -std::numeric_limits<double>::infinity())
		std::cout << "-inf" << std::endl;
	else
		std::cout << static_cast<double>(_num) << std::endl;
}


void	Converter::convert(const std::string& name)const
{
	std::string params[4] = {"char", "int", "float", "double"};
	Converter::f func[4] = {
		&Converter::convertToChar,
		&Converter::convertToInt,
		&Converter::convertToFloat,
		&Converter::convertToDouble
	};

	int i = 0;
	while (i < 4)
	{
		if (name == params[i])
		{
			try{
				(this->*(func[i]))();
			}
			catch (std::exception &e){
				std::cout << e.what() << std::endl;
			}
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << "unknown type" << std::endl;
}

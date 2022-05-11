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
	return("not displayable");
}

const char *Converter::impossibleToConvert::what() const throw(){
	return("impossible to convert");
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
	//thanks Bsunday for making it happen
	//условно data - (_int)data == 0
	//например есть флоат 1.1 (int)1.1 = 1, тип целочисленная часть
	//если у числа нет штуки после точки, по сабжу нужно дописать .0, а стандартный конверт это не делает
	if (_num - static_cast<int>(_num) == 0 && !std::isnan(_num) && !std::isinf(_num)) {
		std::cout << _num << ".0f" << std::endl;
	} else {
		//signbit определяет, является ли заданное число с плавающей точкой arg отрицательным
		if (std::isinf(_num) && !std::signbit(_num)) {
			std::cout << "+";
		}
		std::cout << _num << "f" << std::endl;
	}
}

void Converter::convertToDouble()const{
		std::cout << "double: ";
	if (std::isnan(_num))
		std::cout << "nan" << std::endl;
	else if (_num - static_cast<int>(_num) == 0 && !std::isnan(_num) && !std::isinf(_num))
 		std::cout << _num << ".0" << std::endl;
	else if (std::isinf(_num) && !std::signbit(_num))
 		std::cout << "+inf" << std::endl;
	else if (-1e-14 <= this->_num && this->_num <= 1e-14)
		std::cout << "0.0" << std::endl;
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

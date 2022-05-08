#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <exception>
#include <cmath>
#include <limits>
#include <iomanip>
//Цель - создание программы, которая входной аргумент преобразует по типу и выводит его
//dynamic_cast преобразует типы только между указателями или ссылками между объектами
//созданными из классов(от родителя к наследникам)
//признаком неудачи служит возврат нулевого значения
//static_cast позволяет изменять только типы, которые преобразованы логически
//static_cast <тип к которому преобразуем> (переменная)
//static_cast <char> (val)
class Converter{
	private:
		double _num;
	public:
		Converter();
		~Converter();
		Converter (const Converter &arg);
		Converter &operator=(const Converter &arg);
		void setValue(double num);
		double getValue()const;
		void convertToChar()const;
		void convertToInt()const;
		void convertToFloat()const;
		void convertToDouble()const;

		void convert(const std::string &arg)const;
		typedef void (Converter::*f)()const;
		class notDisplayable: public std::exception{
						public:
								virtual const char *what() const throw();
					};
		class impossibleToConvert: public std::exception{
						public:
								virtual const char *what() const throw();
					};
};

#endif

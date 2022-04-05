#ifndef FIXED_HPP
# define FIXED_HPP

# define COLOR1 "\e[0;38;5;75m"
# define COLOR2 "\e[0;38;5;216m"
# define COLOR3 "\e[0;38;5;141m"
# define COLOR4 "\e[0;38;5;157m"
# define END "\e[37;0m"

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

class Fixed
{
	private:
		int n_int; // Целое число для хранения значения с фиксированной точкой
		static const int f_bit = 8; // Статическое постоянное целое число для хранения количества дробных битов
// Этой константой всегда будет фиксированное значение 8.

	public:
		Fixed(); // Конструктор по умолчанию, который иниц знач фикс—ой точки = 0
		~Fixed(); // Деструктор

		Fixed(int value);
		Fixed(float bits);
		Fixed(const Fixed &arg); // Конструктор копирования

		Fixed& operator= (const Fixed &arg); // Перегрузка оператора присваивания

		int getRawBits(void) const; // возвращает исходное знач фикс—ой точкой
		void setRawBits(int const raw); // задает исходное знач фикс—ой точкой // raw — переменная

		float toFloat(void) const; // преобразует значение с фиксированной точкой в значение с плавающей точкой.
		int toInt(void) const; // преобразует значение с фиксированной точкой в целое значение.

////
		static Fixed& min(Fixed &val1, Fixed &val2);
		static Fixed& max(Fixed &val1, Fixed &val2);
// Перегрузка min и max
		static Fixed const& min(const Fixed &val1, const Fixed &val2);
		static Fixed const& max(const Fixed &val1, const Fixed &val2);

		Fixed	operator*(Fixed const &val) const;

		Fixed&	operator++(void); //++a
		Fixed	operator++(int); //a++

		bool	operator>(Fixed const &val) const;
		bool	operator<(Fixed const &val) const;

// неиспользуемые операторы

		bool	operator>=(Fixed const &val); //	>=
		bool	operator<=(Fixed const &val); //	<=
		bool	operator==(Fixed const &val); // ==
		bool	operator!=(Fixed const &val);	// !=

		Fixed	operator+(Fixed const &val);	// +
		Fixed	operator-(Fixed const &val);	// -
		Fixed	operator/(Fixed const &val);	// /

		Fixed&	operator--(void); //--a
		Fixed	operator--(int); //a--
};
// ostream – выходной поток // перегрузка <<
// Перегрузка = функция + "operator" + символ перегружаемого оператора
// Перегружаемый оператор определяется как метод класса
std::ostream& operator<< (std::ostream& cout, const Fixed &point_a);

#endif

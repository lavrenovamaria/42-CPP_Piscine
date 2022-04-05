#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int                 _fix_p_value;
	static const int    _n_fr_bits = 8;
public:
	Fixed();
	Fixed(const int fixedPointValue);
	Fixed(const float floatingPointValue);

	Fixed(const Fixed &arg);
	~Fixed();

	Fixed   &operator=(const Fixed &arg);

	int     getRawBits() const;
	void    setRawBits(const int raw);

	int     toInt() const;//преобразует значение с фиксированной точкой в значение с плавающей точкой
	float   toFloat() const;//преобразует значение с фиксированной точкой в целое значение
};

std::ostream &operator<<(std::ostream &cout, Fixed const &point_a);

#endif
